#ifndef ROOTTREE_H
#define ROOTTREE_H

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"

#include "Event.h"

class RootTree { //: public TObject {
 public:
  RootTree();
  ~RootTree();

  void fillTree(Event*);

 private:
  TTree* rootTree;
  Event* event;
  TFile* rootFile;
}; 
#endif 
