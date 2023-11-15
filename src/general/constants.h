#ifndef MOLECULARDYNAMICS_CONSTANTS_H
#define MOLECULARDYNAMICS_CONSTANTS_H

#include <cmath>

namespace constants {
    namespace particles {
        const double MASS = 66.335;
        const double BOLTZMANN_CONSTANT = 1.380648528;
    }

    namespace potential {
        const double EPS = 1.712;
        const double SIGMA = 0.3418;
        const double RADIUS_CUT = 2.5 * SIGMA;
        const double U_CUT = 4 * EPS * (pow((SIGMA / RADIUS_CUT), 12) - pow((SIGMA / RADIUS_CUT), 6));
    }

}

#endif //MOLECULARDYNAMICS_CONSTANTS_H
