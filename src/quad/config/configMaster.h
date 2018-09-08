#ifndef __CONFIGMASTER_H
#define __CONFIGMASTER_H

#include "led.h"
#include "serial.h"

typedef struct master_s {
	uint8_t version;
	uint16_t size;
	uint8_t magic_be;			// magic number, should be 0xBE
	serialPinConfig_t serialPinConfig;
	serialConfig_t	serialConfig;
	LedStatusConfig_t ledStatusConfig;
}master_t;

extern master_t masterConfig;

#define LedStatusConfig(x)					(&masterConfig.ledStatusConfig)
#define SerialPinConfig(x) 					(&masterConfig.serialPinConfig)
#define SerialConfig(x)						(&masterConfig.serialConfig)

#endif	// __CONFIGMASTER_H
