
#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#include "Adc.h"
/*	!COMMENT: I CHANGED THE SENSORS CHANNELS TO SUIT THE SIMULATION NOT THE HARDAWRE CONNECTIONS */
#define SENSOR1_PIN     0
#define SENSOR2_PIN     4
#define SENSOR3_PIN     5
#define SENSOR4_PIN     6
#define SENSOR5_PIN     7


void Sensors_Init(void);

uint16 Sensor_Generic_ValueGet(uint8 channel);

#endif /* POTENTIOMETER_H_ */