#include "Car.h"
#include <iostream>

int main() {
    Motor motor1 = {120, 1.6f, 6500};
    Motor motor2 = {150, 2.0f, 7000};
    Motor motor3 = {110, 1.4f, 6000};

    Car car1("Toyota", "Corolla", 2020, motor1, &motor1);
    Car car2("Honda", "Civic", 2022, motor2, &motor2);
    Car car3("Ford", "Fiesta", 2018, motor3, &motor3);

    std::cout << "=== DATOS DE LOS COCHES ===" << std::endl;
    car1.mostrarDatos();
    std::cout << std::endl;

    car2.mostrarDatos();
    std::cout << std::endl;

    car3.mostrarDatos();
    std::cout << std::endl;

    std::cout << "=== COMPARACION DE CABALLOS ===" << std::endl;
    if (car1.tieneMasCaballosQue(car2)) {
        std::cout << "El Toyota tiene mas caballos que el Honda." << std::endl;
    } else {
        std::cout << "El Toyota NO tiene mas caballos que el Honda." << std::endl;
    }

    if (car2.tieneMasCaballosQue(car3)) {
        std::cout << "El Honda tiene mas caballos que el Ford." << std::endl;
    } else {
        std::cout << "El Honda NO tiene mas caballos que el Ford." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== COMPARACION DE RPM ===" << std::endl;
    if (car1.moreRPM(&car2)) {
        std::cout << "El Toyota tiene mas RPM maximas que el Honda." << std::endl;
    } else {
        std::cout << "El Toyota NO tiene mas RPM maximas que el Honda." << std::endl;
    }

    if (car2.moreRPM(&car3)) {
        std::cout << "El Honda tiene mas RPM maximas que el Ford." << std::endl;
    } else {
        std::cout << "El Honda NO tiene mas RPM maximas que el Ford." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== ACCESO AL MOTOR CON getMotor() ===" << std::endl;
    const Motor* motor_car1 = car1.getMotor();

    std::cout << "Motor del Toyota:" << std::endl;
    std::cout << "Caballos: " << motor_car1->caballos_de_fuerza << std::endl;
    std::cout << "Cilindrada: " << motor_car1->cilindrada << std::endl;
    std::cout << "RPM maximo: " << motor_car1->rpm_maximo << std::endl;

    std::cout << std::endl;
    std::cout << "=== PRUEBA CON nullptr ===" << std::endl;
    if (!car1.moreRPM(nullptr)) {
        std::cout << "Comparacion con puntero nulo controlada correctamente." << std::endl;
    }

    return 0;
}