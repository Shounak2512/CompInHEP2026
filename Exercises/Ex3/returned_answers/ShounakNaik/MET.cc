#include "MET.hh"
#include <cmath>

namespace MET {

MET::MET(double met_x, double met_y)
    : met_x(met_x), met_y(met_y) {}

double MET::x() const {
    return met_x;
}

double MET::y() const {
    return met_y;
}

double MET::value() const {
    return std::sqrt(met_x * met_x + met_y * met_y);
}

double MET::phi() const {
    return std::atan2(met_y, met_x);
}

} 
