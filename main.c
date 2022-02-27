
#include "Adc.h"
#include "FlexSensors.h"
#include "USART.h"
#include "SensorsRanges.h"

#include <util/delay.h>

void Speed_Check(uint16 * Speed_Finger);


int main(void)
{
	Sensors_Init();
	UART_INIT();
	
	
	uint16 Finger1_Reading = 0;
	uint16 Finger2_Reading = 0;
	uint16 Finger3_Reading = 0;
 	uint16 Finger4_Reading = 0;
 	uint16 Finger5_Reading = 0;
	
	
	
	while (1)
	{
		Finger1_Reading = Sensor_Generic_ValueGet(SENSOR1_PIN);
		Finger2_Reading = Sensor_Generic_ValueGet(SENSOR2_PIN);
		Finger3_Reading = Sensor_Generic_ValueGet(SENSOR3_PIN);
		Finger4_Reading = Sensor_Generic_ValueGet(SENSOR4_PIN);
		Finger5_Reading = Sensor_Generic_ValueGet(SENSOR5_PIN);
		
		if (Finger2_Reading < 45 && Finger3_Reading < 45 && Finger4_Reading < 45 && Finger5_Reading < 45)
		{
			UART_Tx('s');
			_delay_ms(500);
			
			
		}
		else if (Finger2_Reading > 45 && Finger3_Reading > 45 && Finger4_Reading > 45 && Finger5_Reading > 45)
		{
			UART_Tx('f');
			_delay_ms(500);
			Speed_Check(&Finger1_Reading);
			
		}
		else if (Finger2_Reading < 45 && Finger3_Reading > 45 && Finger4_Reading > 45 && Finger5_Reading > 45)
		{
			UART_Tx('l');
			_delay_ms(500);
			Speed_Check(&Finger1_Reading);
		
		}
		else if (Finger2_Reading < 45 && Finger3_Reading < 45 && Finger4_Reading > 45 && Finger5_Reading > 45)
		{
			UART_Tx('r');
			_delay_ms(500);
			Speed_Check(&Finger1_Reading);
			
		}
		else if (Finger2_Reading < 45 && Finger3_Reading < 45 && Finger4_Reading < 45 && Finger5_Reading > 45)
		{
			UART_Tx('b');
			_delay_ms(500);
			Speed_Check(&Finger1_Reading);
		}
		
       
		
		
		
	
		
	}
}



void Speed_Check(uint16 * Speed_Finger)
{
	
	if (*Speed_Finger < 45)
	{
		UART_Tx('H');
	}
	else
	{
		UART_Tx('L');
	}
	_delay_ms(500);
}