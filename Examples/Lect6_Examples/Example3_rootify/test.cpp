#include "Event.h"
#include "RootTree.h"

#include <iostream>

int main(){

  RootTree* dumper = new RootTree();

  Event* event = new Event;

  for(int i = 0; i < 10; ++i){

    double r = ((double) rand() / (RAND_MAX));
    int nTracks = int(10*r);
    std::cout << "Event " << i << ", tracks " << nTracks << std::endl;

    for(int j = 0; j < nTracks; ++j){
      double px = 10*((double) rand() / (RAND_MAX));
      double py = 10*((double) rand() / (RAND_MAX));
      double pz = 10*((double) rand() / (RAND_MAX));
      double e = sqrt(px*px+py*py+pz*pz);

      Track track(px,py,pz,e);
      std::cout << "    track pt " << track.Pt() << std::endl; 
      event->tracks.push_back(track);

    }
    dumper->fillTree(event);
  }

  delete dumper;
}
