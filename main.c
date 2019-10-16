#include "main.h"
#include <stdio.h>
#include "cf.h"
#include <z80.h>

char text[250];

uint8_t state;
void main()
{
	int i;
	
	//init 
	state = 0xFF;
	while (bitRead(state, 7))
	{
		state = z80_inp(CF_STATUS);
	}
	printf("register 7: %02X \r\n", state);

	z80_outp(CF_BASE_REG + 1, 0x01);
	delayCycles(100);
	z80_outp(CF_COMMAND, 0xEF);
	delayCycles(100);
	z80_outp(CF_BASE_REG + 1, 0x82);
	delayCycles(100);
	z80_outp(CF_COMMAND, 0xEF);
	delayCycles(100);

	// read
	state = 0xFF;
	while (bitRead(state, 7) || !bitRead(state, 6)) // wait for !busy 0x80 and ready 0x40
	{
		state = z80_inp(CF_STATUS);
	}
	
	z80_outp(CF_BASE_REG + 2, 0x01);
	delayCycles(100);
	z80_outp(CF_BASE_REG + 3, 0x00);
	delayCycles(100);
	z80_outp(CF_BASE_REG + 4, 0x00);
	delayCycles(100);
	z80_outp(CF_BASE_REG + 5, 0x00);
	delayCycles(100);
	z80_outp(CF_BASE_REG + 6, 0x00 | 0xE0);
	delayCycles(100);

	z80_outp(CF_COMMAND, 0x20);
	delayCycles(100);

	state = 0xFF;
	while (bitRead(state, 7) || !bitRead(state, 3)) // wait for !busy 0x80 and dry 0x08
	{
		state = z80_inp(CF_STATUS);
	}
	
	for (i = 0; i < 512; i++)
	{
		uint8_t data = z80_inp(CF_BASE_REG + 0);

		if (i % 32 == 0)
		{
			putchar('\r');
			putchar('\n');
		}
		printf("%02X", data);
		
	}
	


	while(1)
	{

	}
}
