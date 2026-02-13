#include "SimParticle.h"

namespace Tracks {

SimParticle::SimParticle(double energy, double px, double py, double pz, int particleId, int parentId)
                        : Track(energy, px, py, pz), m_particleId(particleId), m_parentId(parentId) {}

int SimParticle::particleId() const { return m_particleId; }
int SimParticle::parentId()  const { return m_parentId;  }

}
