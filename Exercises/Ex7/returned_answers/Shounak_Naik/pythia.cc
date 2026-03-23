#include "Pythia8/Pythia.h"
#include <fstream>
#include <iostream>

using namespace Pythia8;

int main() {
    Pythia pythia;

    // Proton-proton collisions at 14 TeV
    pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 14000.");

    // Simplest Higgs production channel: gluon fusion
    pythia.readString("HiggsSM:gg2H = on");

    // Higgs mass = 125 GeV
    pythia.readString("25:m0 = 125.0");

    // Use CTEQ6L1 PDFs (requires LHAPDF support)
    pythia.readString("PDF:pSet = LHAPDF6:cteq6l1");

    pythia.init();

    std::ofstream outFile("higgs_masses.dat");

    int nEvents = 1000;

    for (int iEvent = 0; iEvent < nEvents; iEvent++) {
        if (!pythia.next()) continue;

        // Look for the Higgs boson in the event record
        for (int i = 0; i < pythia.event.size(); i++) {
            if (pythia.event[i].id() == 25) {
                outFile << pythia.event[i].m() << std::endl;
                break; // only one Higgs per event
            }
        }
    }

    outFile.close();
    pythia.stat();

    std::cout << "Done. Higgs masses written to higgs_masses.dat" << std::endl;
    return 0;
}