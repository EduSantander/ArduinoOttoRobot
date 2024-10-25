#include <SoftwareSerial.h> //Quitar los espacios de esta parte  < SoftwareSerial.h >
#include <Otto.h>
SoftwareSerial BT(10,11); // 10 RX, 11 TX.
Otto Otto;  //This is Otto!

#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer  13 

#define triggerPinFront 8
#define echoPinFront 9

// Definir las notas musicales
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_AS4 466 // La#4 o Bb4
#define NOTE_AS5 932 // La#5 o Bb5

// Duración de las notas
int noteDurations[] = {
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 2
};

// Melodía de "Cumpleaños Feliz"
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, // "Cumpleaños fe-liz"
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, // "Cumpleaños fe-liz"
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, // "Te de-se-amos to-dos"
  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4 // "Cumpleaños fe-liz"
};


char CharIN = ' ';


#define triggerPinFront 6
#define echoPinFront 7
#define triggerPinLeft 8
#define echoPinLeft 9
#define triggerPinRight 10
#define echoPinRight 11

unsigned long previousMillis = 0;  // Para manejar el tiempo sin delay
const long interval = 100;  // Intervalo de chequeo en milisegundos

int lastTurnDirection = 0;  // 0 = ninguno, 1 = izquierda, -1 = derecha

long readUltrasonic(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  return pulseIn(echoPin, HIGH) / 58;  
}

void moveForward(int speed) {
  Otto.walk(1, speed, 1);  // Velocidad ajustable
}

void turnRight(int speed) {
  Otto.turn(1, speed, -1);  
  lastTurnDirection = -1;  // Marca que Otto giró a la derecha
}

void turnLeft(int speed) {
  Otto.turn(1, speed, 1);  
  lastTurnDirection = 1;  // Marca que Otto giró a la izquierda
}

void moveBackward(int speed) {
  Otto.walk(1, speed, -1);  
}


void setup()  
{
  Serial.begin(9600); 
  BT.begin(9600); 
  Serial.println("Iniciando Control ...");
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  Otto.sing(S_connection); //Otto wake up!
  Otto.home();

  pinMode(triggerPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(triggerPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(triggerPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);



}


void loop(){  
    if(BT.available()){
      CharIN = BT.read();
      Serial.print(CharIN);
      if(CharIN == 'a'){
        Otto.home();
        // Reproducir la melodía
        for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++) {
          // Calcular la duración de cada nota
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(13, melody[thisNote], noteDuration);
          
          // Pausa entre las notas
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          
          // Apagar el buzzer entre notas
          noTone(13);
        }
        
        // Pausa antes de volver a tocar la canción
        delay(2000);
      }
      if(CharIN == 'b'){
        //BAILE PANA OTTO
        Otto.moonwalker(4, 600, 25,1); //LEFT    // 0.01 al 0.08
        Otto.moonwalker(4, 600, 25,-1); //RIGHT  // 0.01 al 0.08
        Otto.walk(3,900,1);                      // 0.08 al 0.14
        Otto.walk(3,900,-1);                     // 0.08 al 0.14
        Otto.swing(4, 1300, 40);                 // 0.14 al 0.20
         Otto.home();
        Otto.sing(S_OhOoh);
         delay(200);
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 0.20 al 0.39 
        Otto.moonwalker(6, 400, 25,-1); //RIGHT  // 0.20 al 0.39 
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 0.20 al 0.39 
        Otto.moonwalker(6, 400, 25,-1); //RIGHT  // 0.20 al 0.39 
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 0.20 al 0.39 
        Otto.moonwalker(6, 400, 25,-1); //RIGHT  // 0.20 al 0.39 
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 0.20 al 0.39 
         Otto.home();
        Otto.sing(S_mode1);
         delay(200);
        Otto.flapping(7, 800, 20,1);             // 0.39 al 0.50
        Otto.flapping(7, 800, 20,-1);            // 0.39 al 0.50
        Otto.crusaito(7, 900, 20,1);             // 0.50 al 1.03
        Otto.crusaito(7, 900, 20,-1);            // 0.50 al 1.03
        Otto.playGesture(OttoMagic);
        Otto.swing(5,2500, 60);                  // 1.03 al 1.16
        Otto.walk(4,900,1);                      // 1.16 al 1.22
        Otto.moonwalker(4, 600, 25,1); //LEFT    // 1.16 al 1.22
        Otto.walk(4,900,-1);                     // 1.22 al 1.21
        Otto.moonwalker(4, 600, 25,-1); //RIGHT  // 1.28 al 1.40
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 1.28 al 1.40
        Otto.moonwalker(6, 400, 25,-1); //RIGHT  // 1.28 al 1.40 
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 1.28 al 1.40 
        Otto.moonwalker(6, 400, 25,-1); //RIGHT  // 1.28 al 1.40
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 1.28 al 1.40
        Otto.moonwalker(6, 400, 25,-1); //RIGHT  // 1.28 al 1.40
        Otto.moonwalker(6, 400, 25,1); //LEFT    // 1.28 al 1.40 
        
        Otto.home();
        Otto.sing(S_cuddly); 
        delay(2000);

      }

      if(CharIN == 'c'){
      unsigned long currentMillis = millis();  // Tiempo actual

        // Si ha pasado suficiente tiempo desde la última verificación
        if (currentMillis - previousMillis >= interval) {
          previousMillis = currentMillis;

          int distanceFront = readUltrasonic(triggerPinFront, echoPinFront);
          int distanceLeft = readUltrasonic(triggerPinLeft, echoPinLeft);
          int distanceRight = readUltrasonic(triggerPinRight, echoPinRight);

          // Ajuste dinámico de la velocidad en función de la distancia
          int speed = 1000;  // Velocidad estándar
          if (distanceFront < 30) speed = 500;  // Reduce la velocidad si se acerca un obstáculo

          if (distanceFront < 15) {
            // Si hay un obstáculo en frente, decide la dirección de giro
            if (distanceLeft > distanceRight && lastTurnDirection != 1) {
              turnLeft(1000);  // Gira a la izquierda si es más despejado y no ha girado antes
            } else if (distanceRight > distanceLeft && lastTurnDirection != -1) {
              turnRight(1000);  // Gira a la derecha si es más despejado y no ha girado antes
            } else {
              // Si ambas direcciones están bloqueadas o se ha girado ya, retrocede y gira
              moveBackward(500);
              if (lastTurnDirection == 1) {
                turnRight(1000);  // Cambia de dirección después de retroceder
              } else {
                turnLeft(1000);
              }
            }
          } else {
            // Avanza si no hay obstáculos cerca
            moveForward(speed);
          }
        } 
    }
  }
}
