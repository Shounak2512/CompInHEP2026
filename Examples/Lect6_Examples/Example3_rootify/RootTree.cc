#include "RootTree.h"

RootTree::RootTree(){

  rootFile = TFile::Open("analysis.root", "RECREATE");
  rootFile->SetCompressionLevel(1);

  rootTree = new TTree("rootTree","events");
  rootTree->SetAutoSave(1000000000);
  event  = new Event(); 
  int bufsize = 256000;
  int split   = 1;
  rootTree->Branch("Event","Event",&event,bufsize,split);

}

RootTree::~RootTree(){

  rootFile->cd();
  rootTree->Write();
  rootFile->ls();
  rootFile->Close();
  delete rootFile;
}

void RootTree::fillTree(Event* e){

  event = e;
  rootFile->cd();
  rootTree->Fill();
}
