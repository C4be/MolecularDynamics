#ifndef MOLECULARDYNAMICS_PARTICLE_H
#define MOLECULARDYNAMICS_PARTICLE_H

#include<vector>
#include<memory>
#include<cmath>

#include "../general/constants.h"
#include "../general/params.h"

class Particle {
private:
    std::shared_ptr<std::vector<double>> position;
    std::shared_ptr<std::vector<double>> velocity;
    std::shared_ptr<std::vector<double>> force;

public:
    Particle(const std::vector<double> &position, const std::vector<double> &velocity);

    void updateVelocityHalfStep();

    void updatePosition();

    void updateForces(const std::vector<double> &normalize, double F);

    void resetForces();

    void checkPGU();

    static double calculateDistance(const Particle &firstParticle, const Particle &secondParticle);

    static std::vector<double>
    calculateParticleInteraction(const Particle &firstParticle, const Particle &secondParticle);

    static std::vector<double> rij(const Particle &firstParticle, const Particle &secondParticle);
};


#endif //MOLECULARDYNAMICS_PARTICLE_H
