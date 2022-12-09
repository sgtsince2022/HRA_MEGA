#include <Arduino.h>
#define BT Serial2
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
#define M11 6//Phai in1
#define M12 5//Phai in2
#define M21 4//Trai in3
#define M22 3//Trai in4
#define ENA 7//Phai
#define ENB 2//Trai
#define pwmQuay 180
#define pwmCheoCham 95

void setPWM(bool MOTOR, int pwm) {
    if (MOTOR) {
        digitalWrite(M11,(pwm>=0));
        digitalWrite(M12,(pwm<=0));
        analogWrite(ENA,abs(pwm));
    } else {
        digitalWrite(M21,(pwm>=0));
        digitalWrite(M22,(pwm<=0));
        analogWrite(ENB,abs(pwm));
    }
}
void stop() {
    analogWrite(ENA,255);
    analogWrite(ENB,255);
    digitalWrite(M11,1);
    digitalWrite(M12,1);
    digitalWrite(M21,1);
    digitalWrite(M22,1);
}
void pinModeSetup(){
    pinMode(M11,OUTPUT);
    pinMode(M12,OUTPUT);
    pinMode(M21,OUTPUT);
    pinMode(M22,OUTPUT);
    pinMode(ENA,OUTPUT);
    pinMode(ENB,OUTPUT);
}