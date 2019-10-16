#include "main.h"
#include "cf.h"
#include <stdio.h>

char text[250];

void main()
{
	cf_init();
	
	uint8_t* sector = cf_read(0);
	cf_dump_sector(sector);

	printf("\r\n------\r\n");

	snprintf(sector, 32, "Hallo Welt: %d", 23);

	cf_write(0, sector);

	while(1)
	{

	}
}
