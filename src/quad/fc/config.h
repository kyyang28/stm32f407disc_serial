#ifndef __CONFIG_H
#define __CONFIG_H

#include "configMaster.h"

void ResetEEPROM(void);
void CheckEEPROMContainsValidData(void);
void ResetLedStatusConfig(LedStatusConfig_t *ledStatusConfig);
void CreateDefaultConfig(master_t *config);

#endif	// __CONFIG_H
