#include <iostream>
#include <bcm2835.h>
#include <stdio.h>
using namespace std;
//int main(int argc, char **argv)
int main(void)
{
    if (!bcm2835_init())
	return 1;
    bcm2835_gpio_fsel(RPI_GPIO_P1_10, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(RPI_BPLUS_GPIO_J8_08, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_set_pud(RPI_GPIO_P1_10, BCM2835_GPIO_PUD_UP);
    while (1)
    {
	uint8_t value = bcm2835_gpio_lev(RPI_GPIO_P1_10);
	printf("Lectura: %d\n", value);
	if(value > 0)
		bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_08, LOW);
	else
		bcm2835_gpio_write(RPI_BPLUS_GPIO_J8_08, HIGH);
	delay(500);
    }

    bcm2835_close();
    return 0;
}