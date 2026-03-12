#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TStyle.h>

int main() {
    TFile file("rand.root", "READ");
    TTree* tree = nullptr;
    file.GetObject("Tree", tree);

    gStyle->SetCanvasColor(0);
    gStyle->SetPadColor(0);

    TH1F h("h","Gaussian samples;X;Counts", 50, -4, 4);
    tree->Draw("x>>h");

    h.SetLineColor(kBlack);
    h.SetLineWidth(3);
    h.SetFillColor(kYellow);

    TCanvas c("c","plot",800,600);
    h.Draw("HIST");

    TF1 gaus("gaus","gaus",-4,4);
    h.Fit(&gaus, "Q"); // quiet

    c.SaveAs("hist.png");
    return 0;
}
