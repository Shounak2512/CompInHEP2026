#include "Track.h"

ClassImp(Track)

Track::Track(){}
Track::Track(double px, double py, double pz, double e){
  this->SetPxPyPzE(px,py,pz,e);
}
Track::~Track(){}

//Vertex Track::GetVertex(){ return theVertex; }

//void Track::SetVertex(Vertex v){theVertex = v;}
