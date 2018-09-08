#ifndef __RESOURCE_H
#define __RESOURCE_H

typedef enum {
	OWNER_FREE			= 0,
	OWNER_LED,				// 1
	OWNER_BUTTON,			// 2
	OWNER_USB,
	OWNER_SYSTEM,			// 3
	OWNER_SERIAL_TX,
	OWNER_SERIAL_RX,
	OWNER_TOTAL_COUNT
}resourceOwner_e;

#define RESOURCE_INDEX(x)		((x) + 1)
#define RESOURCE_SOFT_OFFSET    10

#endif	// __RESOURCE_H
