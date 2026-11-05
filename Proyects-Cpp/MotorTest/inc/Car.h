#ifndef CAR_H
#define CAR_H

typedef struct {
    int caballos_de_fuerza;
    float cilindrada;
    int rpm_maximo;
} Motor;
class Car{
    public:
        Car();
        Car(const char *brand, const char *model, int year, const Motor& motor, Motor *motor_ptr);
        
        void mostrarDatos() const;
        const Motor* getMotor() const;
        bool tieneMasCaballosQue(const Car& other) const;
        bool moreRPM(const Car* other) const;

    private:
        char m_brand[20];
        char m_model[20];
        int m_year;
        Motor m_motor;
        Motor *m_motor_ptr;
};
#endif // __MOTOR_H__