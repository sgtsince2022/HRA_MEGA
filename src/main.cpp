#include <main.h>
char cmd;
void ButtonControl(char cmd){
  Serial.println(cmd);
  switch(cmd){
    case 'F':
      setPWM(RIGHT_MOTOR,255);
      setPWM(LEFT_MOTOR,255);
      break;
    case 'B':
      setPWM(RIGHT_MOTOR,-255);
      setPWM(LEFT_MOTOR,-255);
      break;
    case 'L':
      setPWM(LEFT_MOTOR,-pwmQuay);
      setPWM(RIGHT_MOTOR,pwmQuay);
      break;
    case 'R':
      setPWM(LEFT_MOTOR,pwmQuay);
      setPWM(RIGHT_MOTOR,-pwmQuay);
      break;
    case 'G':
      setPWM(LEFT_MOTOR,pwmCheoCham);
      setPWM(RIGHT_MOTOR,255);
      break;
    case 'I':
      setPWM(LEFT_MOTOR,255);
      setPWM(RIGHT_MOTOR,pwmCheoCham);
      break;
    case 'H':
      setPWM(RIGHT_MOTOR,-255);
      setPWM(LEFT_MOTOR,-pwmCheoCham);
      break;
    case 'J':
      setPWM(LEFT_MOTOR,-255);
      setPWM(RIGHT_MOTOR,-pwmCheoCham);
      break;
    case 'S':
      stop();
  }
}

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinModeSetup();
}
void loop() {
  cmd=BT.read();
  ButtonControl(cmd);
}