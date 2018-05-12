#include <usart.h>
#include "gpio.h"

#define clear_screen "\x1b[2J\x1b[H"

uint8_t Test[] = "Hello World\n\r"; //Data to send
uint8_t bTxBuffer1[]= "";

char aTxBuffer[] = "";
char USART2TxBuffer[240];

/* Buffer used for reception */
uint8_t aRxBuffer[1];

void serial_print(char *s)
{

	char new_line[]="\r\n";//new line/carriage return

	memset(&USART2TxBuffer[0], 0, sizeof(USART2TxBuffer));//erase the old info from char array

	strcpy(USART2TxBuffer,*(&s));//copy the  string passed from the function to the TX buffer. *(&s)= pointer to the adress where the string is located(in memory)

	HAL_UART_Transmit(&huart2,USART2TxBuffer,sizeof(USART2TxBuffer),64);// Sending in normal mode

	HAL_UART_Transmit(&huart2,new_line,sizeof(new_line),1);//new line
}
