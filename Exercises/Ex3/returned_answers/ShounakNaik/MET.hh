#ifndef MET_H
#define MET_H

namespace MET {

class MET {
public:
    MET(double met_x, double met_y);

    double x() const;
    double y() const;

    double value() const;

    double phi() const;

private:
    double met_x{0.0};
    double met_y{0.0};
};

} 

#endif 