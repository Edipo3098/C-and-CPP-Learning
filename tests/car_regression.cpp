#include "Car.h"
#include <cstdlib>

int main() {
    Motor low{120, 1.6f, 6000};
    Motor high{150, 2.0f, 7000};
    Car first("A", "B", 2020, low, &low);
    Car second("C", "D", 2021, high, &high);
    Car empty;
    Car missing_motor("A", "B", 2020, low, nullptr);
    Car missing_names(nullptr, nullptr, 2020, low, &low);
    Car long_names("A name much longer than the fixed buffer", "Another name much longer than the buffer", 2020, low, &low);
    long_names.mostrarDatos();
    missing_names.mostrarDatos();
    if (empty.moreRPM(&second) || first.moreRPM(nullptr) || missing_motor.moreRPM(&second)) return EXIT_FAILURE;
    if (first.moreRPM(&second) || !second.moreRPM(&first)) return EXIT_FAILURE;
    if (!second.tieneMasCaballosQue(first) || first.tieneMasCaballosQue(second)) return EXIT_FAILURE;
    if (first.getMotor()->rpm_maximo != 6000) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
