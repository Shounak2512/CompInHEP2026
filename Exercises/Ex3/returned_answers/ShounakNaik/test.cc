#include "MET.hh"
#include <cassert>
#include <cmath>
#include <iostream>

static bool nearly_equal(double a, double b, double eps = 1e-12) {
    return std::fabs(a - b) < eps;
}

int main() {
    using MET::MET;

    MET met(30.0, 40.0);

    assert(nearly_equal(met.x(), 30.0));
    assert(nearly_equal(met.y(), 40.0));

    assert(nearly_equal(met.value(), 50.0));

    // Phi check
    const double expected_phi = std::atan2(40.0, 30.0);
    assert(nearly_equal(met.phi(), expected_phi));

    std::cout << "All tests passed!\n";
    std::cout << "MET x   = " << met.x() << "\n";
    std::cout << "MET y   = " << met.y() << "\n";
    std::cout << "MET     = " << met.value() << "\n";
    std::cout << "MET phi = " << met.phi() << " rad\n";
    return 0;
}
