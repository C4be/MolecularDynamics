#include "Particle.h"

Particle::Particle(const std::vector<double> &position, const std::vector<double> &velocity) : position(
        std::make_shared<std::vector<double>>(position)), velocity(std::make_shared<std::vector<double>>(velocity)),
        force(std::make_shared<std::vector<double>>(std::vector<double>{0, 0, 0})) {}

void Particle::updateVelocityHalfStep() {
    (*velocity)[0] += (*force)[0] / (2 * constants::particles::MASS) * STEP;
    (*velocity)[1] += (*force)[1] / (2 * constants::particles::MASS) * STEP;
    (*velocity)[2] += (*force)[2] / (2 * constants::particles::MASS) * STEP;
}

void Particle::updatePosition() {
    (*position)[0] += (*velocity)[0] * STEP + (*force)[0] * pow(STEP, 2) / (2 * constants::particles::MASS);
    (*position)[1] += (*velocity)[1] * STEP + (*force)[1] * pow(STEP, 2) / (2 * constants::particles::MASS);
    (*position)[2] += (*velocity)[2] * STEP + (*force)[2] * pow(STEP, 2) / (2 * constants::particles::MASS);
}

void Particle::checkPGU() {
    if ((*position)[0] >= LX) (*position)[0] -= LX;
    if ((*position)[0] < .0) (*position)[0] += LX;
    if ((*position)[1] >= LY) (*position)[1] -= LY;
    if ((*position)[1] < .0) (*position)[1] += LY;
    if ((*position)[2] >= LZ) (*position)[2] -= LZ;
    if ((*position)[2] < .0) (*position)[2] += LZ;
}

double Particle::calculateDistance(const Particle &firstParticle, const Particle &secondParticle) {
    double dx = (*firstParticle.position)[0] - (*secondParticle.position)[0];
    double dy = (*firstParticle.position)[1] - (*secondParticle.position)[1];
    double dz = (*firstParticle.position)[2] - (*secondParticle.position)[2];
    return sqrt(dx * dx + dy * dy + dz * dz);
}

std::vector<double>
Particle::calculateParticleInteraction(const Particle &firstParticle, const Particle &secondParticle) {
    // TODO: добавить расчет второго слагаемого при расчете давления (возможно)
    double distance = calculateDistance(firstParticle, secondParticle);
    double param = constants::potential::SIGMA / distance;

    double second_tmp = pow(param, 6);
    double first_tmp = pow(second_tmp, 2);


    double U = 4 * constants::potential::EPS * (first_tmp - second_tmp) - constants::potential::U_CUT;
    double F = 24 * constants::potential::EPS * (2.0 * first_tmp - second_tmp) / distance;

    auto UF = std::vector<double>{U, F};

    return UF;
}

void Particle::updateForces(const std::vector<double> &normalize, double F) {
    (*force)[0] += F * normalize[0];
    (*force)[1] += F * normalize[1];
    (*force)[2] += F * normalize[2];
}

void Particle::resetForces() {
    (*force)[0] = .0;
    (*force)[1] = .0;
    (*force)[2] = .0;
}

std::vector<double> Particle::rij(const Particle &firstParticle, const Particle &secondParticle) {
    double rx = (*firstParticle.position)[0] - (*secondParticle.position)[0];
    double ry = (*firstParticle.position)[1] - (*secondParticle.position)[1];
    double rz = (*firstParticle.position)[2] - (*secondParticle.position)[2];

    return std::vector<double>{rx, ry, rz};
}
