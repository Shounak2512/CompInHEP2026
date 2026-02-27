void plotTree() {
    TFile *f = TFile::Open("gaussrand.root");
    TTree *t = (TTree*)f->Get("Tree");

    TH1F *h = new TH1F("h", "Gaussian Distributed Random Numbers;x;Entries", 60, -4, 4);
    t->Draw("x>>h");

    h->SetLineColor(kBlack);
    h->SetLineWidth(3);
    h->SetFillColor(kYellow);
    h->SetFillStyle(1001);

    TCanvas *c = new TCanvas("c", "c", 800, 600);
    c->SetFillColor(kWhite);

    h->Draw("HIST");
    h->Fit("gaus");
    
}