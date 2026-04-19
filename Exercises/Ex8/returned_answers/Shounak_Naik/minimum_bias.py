import pythia8
import numpy as np
import matplotlib.pyplot as plt

NEVENTS = 100000 # 10^4 events did not give a smooth distribution for pt hence using 10^5    
PT_CUT = 5.0        
ETA_CUT = 2.5        

pythia = pythia8.Pythia()

pythia.readString("Beams:idA = 2212")
pythia.readString("Beams:idB = 2212")
pythia.readString("Beams:eCM = 13600.0")

pythia.readString("SoftQCD:nonDiffractive = on")
pythia.readString("SoftQCD:singleDiffractive = on")
pythia.readString("SoftQCD:doubleDiffractive = on")

pythia.init()

muon_pt_all = []   
muon_eta_all = []   

n_events_total = 0  
n_events_detected = 0  

for iEvent in range(NEVENTS):

    # Generate next event
    if not pythia.next():
        continue

    n_events_total += 1

    detected_muon_in_event = False

    for p in pythia.event:

        # Select final-state muons (mu-: 13, mu+: -13)
        if abs(p.id()) == 13 and p.isFinal():

            pt  = p.pT()
            eta = p.eta()

            # Store distributions (Question 1)
            muon_pt_all.append(pt)
            muon_eta_all.append(eta)

            # Check detector acceptance (Question 2)
            if pt > PT_CUT and abs(eta) < ETA_CUT:
                detected_muon_in_event = True

    if detected_muon_in_event:
        n_events_detected += 1

probability = n_events_detected / n_events_total

print(" Minimum Bias Muon Study")
print(f" Total events generated: {n_events_total}")
print(f" Events with detected muons: {n_events_detected}")
print(f" Detection probability: {probability:.4e}")

muon_pt_all  = np.array(muon_pt_all)
muon_eta_all = np.array(muon_eta_all)

plt.hist(muon_pt_all, bins=100, range=(0,15), log=True)
plt.xlabel("Muon $p_T$ (GeV)")
plt.ylabel("Entries")
plt.title("Muon $p_T$ distribution (minimum bias)")
plt.grid(True)
plt.savefig("muon_pt.png")
plt.show()

plt.hist(muon_eta_all, bins=100, range=(-10,10))
plt.xlabel("Muon $\eta$")
plt.ylabel("Entries")
plt.title("Muon $\eta$ distribution (minimum bias)")
plt.grid(True)
plt.savefig("muon_eta.png")
plt.show()
