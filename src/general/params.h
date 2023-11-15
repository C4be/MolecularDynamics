#ifndef MOLECULARDYNAMICS_PARAMS_H
#define MOLECULARDYNAMICS_PARAMS_H

const int NSTEPS = 1000;

// число элементарных ячеек (кристаллов) по осям координат
const int NUMCRIST_X = 2; // число элементарных ячеек по оси X
const int NUMCRIST_Y = 2; // число элементарных ячеек по оси Y
const int NUMCRIST_Z = 2; // число элементарных ячеек по оси Z

// const int NUMBERPARTICLES = NUMCRIST_X * NUMCRIST_Y * NUMCRIST_Z;
const int NUMBERPARTICLES = 2; //число частиц
const double STEP = 0.002; // шаг интегрирования разностной схемы

// размеры системы по осям координат
const double ACRIST = 1.0;
const double LX = NUMCRIST_X * ACRIST, LY = NUMCRIST_Y * ACRIST, LZ = NUMCRIST_Z * ACRIST;
const double VOLUME = LX * LY * LZ; // объем системы

#endif //MOLECULARDYNAMICS_PARAMS_H
