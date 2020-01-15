#include <M5Stack.h>

// Constantes 

int canalPWMCorrea=1;
int FrecuenciaCorrea=300;
int PWMCorrea=8;
int pinCorrea=16;

int canalPWMPlato=2;
int FrecuenciaPlato=70;
int PWMPlato=8;
int pinPlato=21;
int ApagarPWM=0;
int ActivarPWM=128;

int Bomba=12;
int ElectroValvula=15;

int Activar=1;
int Desactivar=0;

int SensorSemilla= 2;
int SensorInductivo=18;


void IRAM_ATTR ISR() {
    Serial.print("Sensor Semilla");
}


void IRAM_ATTR ISR2() {
    Serial.print("Sensor Inductivo");
}

void setup() {

// inicializacion PWM

M5.begin();
ledcSetup(canalPWMCorrea,FrecuenciaCorrea,PWMCorrea);
ledcAttachPin(pinCorrea,canalPWMCorrea);
pinMode(pinCorrea,OUTPUT);

ledcSetup(canalPWMPlato,FrecuenciaPlato,PWMPlato);
ledcAttachPin(pinPlato,canalPWMPlato);
pinMode(pinPlato,OUTPUT);

pinMode(Bomba,OUTPUT);
pinMode(ElectroValvula,OUTPUT);

attachInterrupt(SensorSemilla, ISR, RISING);
attachInterrupt(SensorInductivo, ISR2, RISING);


Serial.begin(115200);
Serial.flush();
delay(50);
Serial.print("M5Stack initializing...");
 



}

void loop() {


ledcWrite(canalPWMCorrea,ActivarPWM);
ledcWrite(canalPWMPlato,ActivarPWM);


digitalWrite(ElectroValvula,Desactivar);
delay(5000);
digitalWrite(ElectroValvula,Desactivar);
delay(5000);

M5.update();

}
                                                   
