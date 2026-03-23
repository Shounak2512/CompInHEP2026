#ifndef TRACK_H
#define TRACK_H

#include "TLorentzVector.h"
//#include "Vertex.h"

class Track : public TLorentzVector {
    public:
	Track();
	Track(double,double,double,double);

	~Track();

	//	Vertex GetVertex();
	//	void SetVertex(Vertex);

    protected:
	//	Vertex theVertex;

    public:
	ClassDef(Track,1)
};
#endif
