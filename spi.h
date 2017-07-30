#define SPI_DDR 	DDRB
#define SPI_PORT	PORTB
#define SS 			PB2
#define SCK			PB5
#define MOSI		PB3
#define MISO		PB4

#include <avr/io.h>

void spiInit(void);
uint8_t spiTransfer(uint8_t data);

void spiInit(void){

	if(!(SPI_DDR & SS))
		SPI_PORT |= (1 << SS);

	SPI_DDR |= (1 << SS);

	SPI_DDR |= (1 << SCK) | (1 << MOSI);
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

uint8_t spiTransfer(uint8_t data){
	//SPI_PORT &= ~(1 << SS);
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
	//SPI_PORT |= (1 << SS);
	return SPDR;
}