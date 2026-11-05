#include "Car.h"
#include <iostream>
#include <cstring>

Car::Car() {
    std::strcpy(m_brand, "");
    std::strcpy(m_model, "");
    m_year = 0;
    m_motor.caballos_de_fuerza = 0;
    m_motor.cilindrada = 0.0f;
    m_motor.rpm_maximo = 0;
}

Car::Car(const char *brand, const char *model, int year, const Motor& motor, Motor *motor_ptr) {
    std::strncpy(m_brand, brand != nullptr ? brand : "", sizeof(m_brand) - 1);
    m_brand[sizeof(m_brand) - 1] = '\0';

    std::strncpy(m_model, model != nullptr ? model : "", sizeof(m_model) - 1);
    m_model[sizeof(m_model) - 1] = '\0';

    m_year = year;
    m_motor = motor;
    m_motor_ptr = motor_ptr;
}

void Car::mostrarDatos()  const{
    std::cout << "Marca: " << m_brand << std::endl;
    std::cout << "Modelo: " << m_model << std::endl;
    std::cout << "Año: " << m_year << std::endl;
    std::cout << "Caballos: " << m_motor.caballos_de_fuerza << std::endl;
    std::cout << "Cilindrada: " << m_motor.cilindrada << std::endl;
    std::cout << "RPM maximo: " << m_motor.rpm_maximo << std::endl;
}

const Motor* Car::getMotor() const {
    return &m_motor;
}


bool Car::tieneMasCaballosQue(const Car &other) const {

       
    return m_motor.caballos_de_fuerza > other.m_motor.caballos_de_fuerza ;
        
    
}


bool Car::moreRPM(const Car* other) const {

        if (other == nullptr || m_motor_ptr == nullptr) {
            std::cerr << "Error: La comparacion requiere un coche y un motor validos." << std::endl;
            return false; // O podrías lanzar una excepción dependiendo de tu diseño
        }
        else
        {
                return m_motor_ptr->rpm_maximo > (*other).m_motor.rpm_maximo ;
        }
    
}

