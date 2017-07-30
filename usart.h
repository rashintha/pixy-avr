#define BAUD 19200 // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1) // set baudrate value for UBRR
#define F_CPU 16000000UL // set the CPU clock

#include <avr/io.h>
#include <string.h>

void usartInit(void);
void usartTransmit(uint8_t data);
void serialPrintln(char* data);
void serialPrint(char* data);

void usartInit (void){
    UBRR0H = (BAUDRATE >> 8);
    UBRR0L = BAUDRATE;   //set baud rate
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0); //enable receiver and transmitter
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);// 8bit data format
}

void usartTransmit(uint8_t data){
    while (!( UCSR0A & (1<<UDRE0))); // wait while register is free
    UDR0 = data; // load data in the register
}

void serialPrintln(char* data){
	for(uint32_t i = 0; i < strlen(data); i++){
		usartTransmit(data[i]);
	}
	usartTransmit('\n');
}

void serialPrint(char* data){
	for(uint32_t i = 0; i < strlen(data); i++){
		usartTransmit(data[i]);
	}
}