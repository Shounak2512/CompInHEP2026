void makeTree() {
    int N=1000;
    double x;

    TFile *file = new TFile("gaussrand.root", "RECREATE");

    TTree *tree = new TTree("Tree","Gaussian random numbers");

    tree->Branch("x", &x, "x/D");

    TRandom3 randGen(0);

    for (int i=0; i < N; i++) {
        x = randGen.Gaus(0,1);
        tree->Fill();
    }

    tree->Write();
    file->Close();

    std::cout << "TFile generated containing" << N << "Gaussian distributed random numbers" << std::endl;
}