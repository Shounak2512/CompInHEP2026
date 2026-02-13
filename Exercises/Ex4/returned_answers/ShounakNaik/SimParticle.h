#ifndef SIM_PARTICLE_H
#define SIM_PARTICLE_H

#include "4-mom.h"

namespace Tracks {

class SimParticle : public Track {
    public:

        SimParticle(double energy, double px, double py, double pz, int particleId, int parentId);
        
        int particleId() const;
        int parentId() const;

    private:
        int m_particleId;
        int m_parentId;
    };

} 

#endif