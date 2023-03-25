#include <stdlib.h>
#include <stdint.h>
#include <util/delay.h>

int main()
{
  *((volatile uint8_t*)0x24) |= (1 << 5);

  while (1)
  {
    *((volatile uint8_t*)0x25) |= (1 << 5);
    _delay_ms(1500);
    *((volatile uint8_t*)0x25) &= ~(1 << 5);
    _delay_ms(1500);
  }

  return 0;
}