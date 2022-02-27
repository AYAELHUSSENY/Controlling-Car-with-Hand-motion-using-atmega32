
#include "FlexSensors.h"

void Sensors_Init(void)
{
	Adc_Init(&gStrAdc_Configuration);
}

uint16 Sensor_Generic_ValueGet(uint8 channel)
{
	uint16 u16LocalAdcReading = 0U;
	Adc_StartGroupConversion(ADC_GROUP_0);
	Adc_ReadChannel((Adc_ChannelType) channel, gStrAdc_Configuration.Resolution, &u16LocalAdcReading);
	return u16LocalAdcReading;
	Adc_StartGroupConversion(ADC_GROUP_0);
}
