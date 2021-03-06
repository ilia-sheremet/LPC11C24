/*
===============================================================================
 Name        : OlimexBoard11C24.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "sys_config.h"
#include "chip.h"

#include <cr_section_macros.h>
#include <stdio.h>

#define CHIP_LPC11CXX
#define DEBUG_ENABLE
#define DEBUG_UART LPC_USART

#define DEBUGINIT() Board_Debug_Init()
#define DEBUGOUT(...) printf(__VA_ARGS__)
#define DEBUGSTR(str) Board_UARTPutSTR(str)
#define DEBUGIN() Board_UARTGetChar()

/* Sends a character on the UART */
void Board_UARTPutChar(char ch)
{
#if defined(DEBUG_UART)
	Chip_UART_SendBlocking(DEBUG_UART, &ch, 1);
#endif
}

/* Gets a character from the UART, returns EOF if no character is ready */
int Board_UARTGetChar(void)
{
#if defined(DEBUG_UART)
	uint8_t data;

	if (Chip_UART_Read(DEBUG_UART, &data, 1) == 1) {
		return (int) data;
	}
#endif
	return -1;
}

/* Outputs a string on the debug UART */
void Board_UARTPutSTR(char *str)
{
#if defined(DEBUG_UART)
	while (*str != '\0') {
		Board_UARTPutChar(*str++);
	}
#endif
}

/* Initialize debug output via UART for board */
void Board_Debug_Init(void)
{
#if defined(DEBUG_UART)
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* RXD */
	Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* TXD */

	/* Setup UART for 115.2K8N1 */
	Chip_UART_Init(LPC_USART);
	Chip_UART_SetBaud(LPC_USART, 115200);
	Chip_UART_ConfigData(LPC_USART, (UART_LCR_WLEN8 | UART_LCR_SBS_1BIT));
	Chip_UART_SetupFIFOS(LPC_USART, (UART_FCR_FIFO_EN | UART_FCR_TRG_LEV2));
	Chip_UART_TXEnable(LPC_USART);
#endif
}

int main(void) {

	SystemCoreClockUpdate();

	DEBUGINIT();

	Chip_GPIO_Init(LPC_GPIO);


	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 10, 1);

	Chip_GPIO_SetPinState(LPC_GPIO, 10, 1, true);

	DEBUGOUT("Hello!");

    // Force the counter to be placed into memory
    volatile static int i = 0 ;

    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }

    return 0 ;
}
