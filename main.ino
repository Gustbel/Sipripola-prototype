// Este código fue diseñado para un proyeto de tesis de Diseño Industrial.
// Este dispositivo hace una señal lumínica (LED) y sonora (BUZZER) cuando una persona que lo lleva puesto hace malos movimientos de fuerza
// Estos movimientos son inclinación hacia adelante inapropiada de espalda y rotación del torso sobre sus pies.
// Para esto último necesitamos dos acelerómetros ya que de este modo tenemos una referencia, de no ser así no sabemos si el sujeto está
//                      haciendo un mal movimiento o solo está caminando. En el caso de la inclinación con el primer aceler es suficiente.

// Se usó Arduino Pro Mini para el microprocesador y 2 módulos acelerómetros con giróscopo MPU9250 para llevar a cabo el proyecto.
// Fue programado en Arduino IDE V1.6.13 para Linux/Ubuntu . Se usó la librería "MPU9250.h" que se puede encontrar facilmente en internet.
// Este proyecto fue diseñado y programado a fines de 2018 por Gustavo Belbruno estudiante de Ingeniería Electrónica (en el momento de escribir esto).
// En caso de alguna consulta por favor escriba a gustavobelbruno@gmail.com 


#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68

MPU9250 IMUuno(SPI,6);
MPU9250 IMUdos(Wire,0x68);   // A4 y A5 de Arduino

int status1, status2;

int led = 7;  //GPIO del led
int buzzer=9, //GPIO del Buzzer
int modulacion=100; //PWM para la señal sonora del Buzzer
float arriba, abajo, resul;

int inclinacionEspalda = 4.4;           //Condición necesaria de inclinacionde espalda del acelerometro, calculada experimentalmente
int giroEspalda = 1.7;                  //Condición necesaria de giro para habilitar el mal movimiento de giro, calculada experimentalmente


void setup() {
    pinMode(led, OUTPUT);

    status1 = IMUuno.begin();
    status2 = IMUdos.begin();
}


void loop() {
  
IMUuno.readSensor();  // read the sensor 1
IMUdos.readSensor();  // read the sensor 2


if(IMUuno.getAccelZ_mss() < -inclinacionEspalda)           // DETECCIÓN DE INCLINACIÓN
    {
        digitalWrite(led, HIGH);   
        analogWrite(buzzer,modulacion); 
    }
else
   {
        digitalWrite(led, LOW);   
        analogWrite(buzzer,0);
   }


//LECTURA DE DATOS DE GIRO:
arriba = IMUuno.getGyroY_rads();
if (arriba<0)
    arriba = -arriba;

abajo = IMUdos.getGyroY_rads();
if (abajo<0)
    abajo = -abajo;


resul= arriba-abajo;      //Diferencia entre giros de un acelerómetro y el otro 
if (resul<0)
    resul = -resul;

if(arriba > giroEspalda && resul > 2)              // DETECIÓN DE GIRO INCORRECTO
   {
        digitalWrite(led, HIGH);
        analogWrite(buzzer,modulacion);
    
        delay (800);
        digitalWrite(led, LOW);
        analogWrite(buzzer,0);   
   }
    
  delay(100);
}
