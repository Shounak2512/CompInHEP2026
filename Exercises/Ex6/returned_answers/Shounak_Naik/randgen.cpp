#include <TTree.h>
#include <TFile.h>
#include <TRandom3.h>

int main() {
    int N=1000;
    TFile file("rand.root","RECREATE");
    TTree tree("Tree","Gaussian rand no.");

    double x;
    tree.Branch("x",&x);
    TRandom3 rand(0);
    
    for (int i; i < N; ++i){
        x=rand.Gaus(0,1);
        tree.Fill();
    }
    tree.Write();
    file.Close();
    return 0;
}