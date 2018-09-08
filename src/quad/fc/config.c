
#include <string.h>
#include "configMaster.h"
#include "led.h"
#include "target.h"
#include "serial.h"

/* master config structure with data independent from profiles */
master_t masterConfig;

void ResetSerialPinConfig(serialPinConfig_t *pSerialPinConfig)
{
	for (int port = 0; port < SERIAL_PORT_MAX_INDEX; port++) {
		pSerialPinConfig->ioTagRx[port] = IO_TAG(NONE);
		pSerialPinConfig->ioTagTx[port] = IO_TAG(NONE);
	}
	
	for (int index = 0; index < SERIAL_PORT_COUNT; index++) {
		switch (serialPortIdentifiers[index]) {
			case SERIAL_PORT_USART1:
				break;

			case SERIAL_PORT_USART2:
				pSerialPinConfig->ioTagRx[SERIAL_PORT_IDENTIFIER_TO_RESOURCE_INDEX(SERIAL_PORT_USART2)] = IO_TAG(UART2_RX_PIN);
				pSerialPinConfig->ioTagTx[SERIAL_PORT_IDENTIFIER_TO_RESOURCE_INDEX(SERIAL_PORT_USART2)] = IO_TAG(UART2_TX_PIN);
				break;

			case SERIAL_PORT_USART3:
				break;

			case SERIAL_PORT_USART4:
				break;

			case SERIAL_PORT_USART5:
				break;

			case SERIAL_PORT_USART6:
				break;

			case SERIAL_PORT_USART7:
				break;

			case SERIAL_PORT_USART8:
				break;

			case SERIAL_PORT_SOFTSERIAL1:
				break;

			case SERIAL_PORT_SOFTSERIAL2:
				break;
			
			case SERIAL_PORT_USB_VCP:
				break;
			
			case SERIAL_PORT_NONE:
				break;
		}
	}
}

void ResetSerialConfig(serialConfig_t *serialConfig)
{
	memset(serialConfig, 0, sizeof(serialConfig_t));
	serialConfig->serial_update_rate_hz = 100;
	serialConfig->reboot_character		= 'R';
	
	for (int index = 0; index < SERIAL_PORT_COUNT; index++) {
		serialConfig->portConfigs[index].identifier			= serialPortIdentifiers[index];
		serialConfig->portConfigs[index].msp_baudrateIndex	= BAUD_115200;
		serialConfig->portConfigs[index].gps_baudrateIndex	= BAUD_115200;		// gps port for debugging purposes
//		serialConfig->portConfigs[index].gps_baudrateIndex	= BAUD_57600;
		serialConfig->portConfigs[index].blackbox_baudrateIndex	= BAUD_115200;
		serialConfig->portConfigs[index].telemetry_baudrateIndex = BAUD_AUTO;
	}
	
	serialConfig->portConfigs[0].functionMask = FUNCTION_MSP;
}

void ResetLedStatusConfig(LedStatusConfig_t *ledStatusConfig)
{
	for (int i = 0; i < LED_NUMBER; i++) {
		ledStatusConfig->ledTags[i] = IO_TAG_NONE;
	}
	
#ifdef LED3
	ledStatusConfig->ledTags[0] = IO_TAG(LED3);	// LED3 = PD13 ==> DEFIO_TAG__PD13 ==> 4D
#endif

#ifdef LED4
	ledStatusConfig->ledTags[1] = IO_TAG(LED4);	// LED4 = PD12 ==> DEFIO_TAG__PD12 ==> 4C
#endif

#ifdef LED5
	ledStatusConfig->ledTags[2] = IO_TAG(LED5);	// LED5 = PD14 ==> DEFIO_TAG__PD14 ==> 4E
#endif

#ifdef LED6
	ledStatusConfig->ledTags[3] = IO_TAG(LED6);	// LED6 = PD15 ==> DEFIO_TAG__PD15 ==> 4F
#endif
	
	ledStatusConfig->polarity = 0;
}

void targetConfiguration(master_t *config)
{
	int index = findSerialPortIndexByIdentifier(SERIAL_PORT_USART2);
	config->serialConfig.portConfigs[index].functionMask = FUNCTION_GPS;
}

void CreateDefaultConfig(master_t *config)
{
	ResetSerialPinConfig(&config->serialPinConfig);
	ResetSerialConfig(&config->serialConfig);
	ResetLedStatusConfig(&config->ledStatusConfig);
	targetConfiguration(config);
}

static void ResetConfig(void)
{
	CreateDefaultConfig(&masterConfig);
}

void ResetEEPROM(void)
{
	ResetConfig();
}

void CheckEEPROMContainsValidData(void)
{
#if 0
	if (isEEPROMContentValid()) {
		return;
	}
#endif
	
	ResetEEPROM();
}
