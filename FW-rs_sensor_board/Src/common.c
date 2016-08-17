#include "common.h"

void delayUS(uint32_t us)
{
	volatile uint32_t counter = 12 * us;
	while (counter--)
		;
}
