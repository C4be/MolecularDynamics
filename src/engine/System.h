#ifndef MOLECULARDYNAMICS_SYSTEM_H
#define MOLECULARDYNAMICS_SYSTEM_H

#include<memory>
#include<vector>

#include "Particle.h"

class System {
private:
    std::shared_ptr<std::vector<std::shared_ptr<Particle>>> data;
    int numberParticles;

public:
    explicit System(const std::vector<Particle> &particles);

    void schemeVerleVirtual();

    void initialForces();

};


#endif //MOLECULARDYNAMICS_SYSTEM_H
