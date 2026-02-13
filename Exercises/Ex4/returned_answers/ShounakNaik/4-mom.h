#ifndef TRACK_H
#define TRACK_H

namespace Tracks{
    class Track {
    public:
        Track();
        Track(double energy, double px, double py, double pz) : E(energy), px(px), py(py), pz(pz) {}

        double Magp()  const;
        double getpT() const;  
        double theta() const; 
        double getEta() const;


    private:
        double E;   
        double px;
        double py;
        double pz;
};

}

#endif 
