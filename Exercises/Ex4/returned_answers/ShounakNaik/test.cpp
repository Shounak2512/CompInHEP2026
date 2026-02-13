#include <iostream>
#include "4-mom.h"
#include "SimParticle.h"

int main() {
    Tracks::Track test(10.0, 3.0, 4.0, 5.0);
    std::cout << "pt=" << test.getpT()
              << ", |p|=" << test.Magp()
              << ", theta=" << test.theta()
              << ", eta=" << test.getEta()
              << std::endl;

              
    Tracks::SimParticle sp(20.0, -1.0, 2.0, 8.0, 13, 11); 
    std::cout << " particleId=" << sp.particleId()
              << " parentId=" << sp.parentId()
              << " sp pt=" << sp.getpT()
              << " |p|=" << sp.Magp()
              << " eta=" << sp.getEta()
              << std::endl;

    return 0;
}
