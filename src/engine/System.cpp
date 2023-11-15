#include "System.h"

System::System(const std::vector<Particle> &particles) {
    data = std::make_shared<std::vector<std::shared_ptr<Particle>>>();
    for (const Particle& p : particles) {
        data->push_back(std::make_shared<Particle>(p));
    }
    numberParticles = (int) particles.size();
}

void System::schemeVerleVirtual() {
    for (const auto& particle : *data) {
        particle->updatePosition({});
        particle->checkPGU();
        particle->updateVelocityHalfStep({});

    }
}

void System::initialForces() { // TODO: переписать под виртуальные частицы
    for (int i = 0; i < numberParticles - 1; ++i) {
        for (int j = i + 1; j < numberParticles; ++j) {
            double distance = Particle::calculateDistance(*(*data)[i], *(*data)[j]);
            if (distance > constants::potential::RADIUS_CUT) continue;

            auto UF = Particle::calculateParticleInteraction(*(*data)[i], *(*data)[j]);
            auto rij = Particle::rij(*(*data)[i], *(*data)[j]);

            // make rij_normalize
            for (auto di : rij) {
                di /= distance;
            }

            (*data)[i]->updateForces(rij, UF[1]);
            (*data)[j]->updateForces(rij, -UF[1]);
        }
    }
}

