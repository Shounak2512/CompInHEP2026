#include <iostream>
#include "4-mom.h"
#include <cmath>

namespace Tracks{

    Track::Track() : E(0.), px(0.), py(0.), pz(0.) {}

    double Track::Magp() const{
        return std::sqrt(std::pow(px,2)+std::pow(py,2)+std::pow(pz,2));
    }

    double Track::theta() const{
        return std::acos(pz/Magp());
    }

    double Track::getpT() const{
        return std::sqrt(std::pow(px,2)+std::pow(py,2));
    }
        
    double Track::getEta() const{
        return -std::log(std::tan(theta()/2));
    }

}
