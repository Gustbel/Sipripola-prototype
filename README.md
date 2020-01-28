# Sipripola-prototype
## Posture Corrector Device at Work

Dispositivo que detecta malos movimientos y posiciones que pudiera tomar la espalda cuando se hacen trabajos de carga y descarga de elementos pesados.

*Device that detects bad movements and positions that could take your back when doing heavy loading and unloading work.*


<img src="https://github.com/Gustbel/Sipripola-prototype/blob/master/images/Top.png" width="800" height="400">


#### El dispositivo emite un sonido de alerta cuando se ejecutan 3 tipos de malos movimientos: 
- Movimiento 1: El usuario levanta una carga del piso sin tener la columna recta y alineada (Imagen 1).
- Movimiento 2: El usuario ejerce rotación y torsión en su torso mientras levanta la carga (Imagen 2).
- Movimiento 3 (No implementado en el prototipo final): El usuario ejerce rotación y torsión en sus muñecas cuando sostiene la carga.

#### *The device emits an alert sound when 3 types of bad movements are executed:*
- *Movement 1: The user lifts a load from the floor without having the column straight and aligned (Image 1).*
- *Movement 2: The user exerts rotation and torsion on his torso while lifting the load (Image 2).*
- *Movement 3 (Not implemented in the final prototype): The user exerts rotation and torsion on their wrists when holding the load.*

<img src="https://github.com/Gustbel/Sipripola-prototype/blob/master/images/Mov1.png" width="170" height="200"> <img src="https://github.com/Gustbel/Sipripola-prototype/blob/master/images/Mov2.png" width="200" height="200">


> - - Imagen 1 - - - - - - - - Imagen 2


#### Funcionamiento / *Functioning* :
Para detectar estos movimientos (1 y 2) se usaron dos sensores acelerómetros. El primero colocado sobre la región lumbar y el segundo sobre la parte superior de la cadera. 
Para detectar el Movimiento 1 se necesita solo leer la inclinación que posee el sensor 1 con respecto al suelo.
Para detectar el Movimiento 2 se contrasta la medición de aceleración de ambos sensores (en un solo eje) y cuando se detecta una discrepancia significativa es una señal de que se ha ejecutado una torsión de columna.

*To detect these movements (1 and 2) two accelerometer sensors were used. The first placed on the lumbar region and the second on the upper part of the hip.
To detect Motion 1, it is only necessary to read the inclination of the sensor 1 with respect to the ground.
To detect Motion 2, the acceleration measurement of both sensors (on a single axis) is contrasted and when a significant discrepancy is detected it is a signal that a column torsion has been executed.*

<img src="https://github.com/Gustbel/Sipripola-prototype/blob/master/images/Med.png" width="1000" height="300">

#### Marco / *Framework* :
Este proyecto fue desarrollado en el marco de una Tesis de Diseño Industrial de la estudiante Macarena Marti. Por un lado se desarrolló el diseño de electrónica (hardware y software) e implementación en PCB a cargo de Gustavo Belbruno, estudiante de Ingeniería Electrónica; y por otro el diseño exterior y ergonómico del dispositivo a cargo de Macarena Marti, estudiante de Diseño Industrial.
El prototipo se desarrolló exitosamente y se utilizó durante la presentación de tesis de Macarena.

*This project was developed within the framework of an Industrial Design Thesis of the student Macarena Marti. On the one hand, the design of electronics (hardware and software) and implementation in PCB was developed by Gustavo Belbruno, student of Electronic Engineering; and on the other, the exterior and ergonomic design of the device by Macarena Marti, Industrial Design student.
The prototype was developed successfully and was used during the thesis presentation of Macarena*



#### Hardware :
- Microcontroller ATmega328 (Arduino Nano), MCU.
- 2 Accelerometer MPU-6500 (connection SPI and I2C). 
- Buzzer. 
- Switch ON/OFF. 
- Battery 9V.

<img src="https://github.com/Gustbel/Sipripola-prototype/blob/master/images/Device.png" width="500" height="917">


#### Futuro / *Future* :
Como mejora a futuro en caso de continuar con el proyecto: - Terminar de diseñar el Movimiento 3. - Dotar al dispositivo de alguna comunicación inalámbrica para poder extraer datos en tiempo real (podría ser WiFi). - Dotar al dispositivo de una batería recargable con un buen análisis de autonomía. - Cambio de componentes por unos más eficientes, especialmente el MCU (podría usarse un ESP32), de este modo rediseñar la placa con un diseño más industrial y que pueda ser replicado de manera industrial en tamaño más pequeño que el conseguido en el prototipo.

*As a future improvement, if the project continues: - Finish designing the Movement 3. - Provide the device with some wireless communication to be able to extract data in real time (it could be WiFi). - Provide the device with a rechargeable battery with a good analysis of autonomy. - Exchange of components for more efficient ones, especially the MCU (an ESP32 could be used), thus redesigning the board with a more industrial design and that can be industrially replicated in a smaller size than that achieved in the prototype.*
