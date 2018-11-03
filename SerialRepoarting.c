/*
 * SerialRepoarting.c
 *
 *  Created on: Oct 10, 2018
 *      Author: vivekhpandya
 *      API's for pushing and visualizing data on serial monitor (SOME FUNCTIONALITY MAY BE SPECIFIC to putty)
 */

#include "stm32l4xx_hal.h"
#include "SerialReporting.h"
#include "ascii_value.h"
#include "string.h"
#include "stdlib.h"

/**
 * @Description : Write at particular cell
 * @Parameter 1 : Data pointer to the first element of string to be written
 * @Parameter 2 : Length of the string (avoid end of the string characters)
 * @Parameter 3 : Row number in table (starts from 1)
 * @Parameter 4 : Column number in table (starts from 1)
 * @Retval    	 : None
 */
void WriteInCell(uint8_t *p_data, uint8_t len_data, uint8_t row_num, uint8_t column_num)
{
	static uint8_t count_len;
	static uint8_t *p_write;
	p_write = &printing_array[row_num-1][LOCATION_COLUMN_(column_num)-1];

	for(count_len=0;count_len<GET_WIDTH_COLUMN(column_num);count_len++)
	{
		if(count_len < len_data)
			*p_write = *p_data;
		else
			*p_write = ' ';
		if(*p_data == 0)	//NULL
			*p_write = ' ';
		p_write++;
		p_data++;
	}
}

/**
 * @Description : Write at particular cell
 * @Parameter 1 : UART handle.
 * @Retval    	: None
 */
void printSerial(UART_HandleTypeDef *huart)
{
	static uint8_t temp_char, count_i;
	static UP_CSR;

	HAL_UART_Transmit(huart,printing_array[0],ARRAY_LENGTH,1000);		//RTOS is creating issue here. So timeout is kept so long. Always keep this in mind to break longer functions in shorter one in RTOS... GoodLearning
	temp_char = CR_ASCII;
	HAL_UART_Transmit(huart,&temp_char,1,50); //carriage-return
	for(count_i = 0;count_i<NO_OF_ROW;count_i++)
		HAL_UART_Transmit(huart,up_csr,3,50);
}

/**
 * @Description : Write at entire particular column
 * @Parameter 1 : Data pointer to the first element of TWO-DIMENTIONAL array to be written
 * @Parameter 2 : Length of the string (avoid end of the string characters)
 * @Parameter 3 : Row number in table (starts from 1)
 * @Parameter 4 : Column number in table (starts from 1)
 * @Retval    	: None
 */
void WriteColumn(uint8_t *p_data, uint8_t len_data, uint8_t column_len, uint8_t column_num)
{
	static uint8_t count_len;

	if(column_len <= NO_OF_COLUMN)
	{
		for(count_len=0;count_len<column_len;count_len++)
		{
			WriteInCell(p_data,len_data,count_len+1,column_num);
			p_data++;
		}
	}
}

/**
 * @Description : Write at entire particular column of integers
 * @Parameter 1 : Data pointer to the first element of TWO-DIMENTIONAL array to be written
 * @Parameter 2 : Row number in table (starts from 1)
 * @Parameter 3 : Column number in table (starts from 1)
 * @Retval    	: None
 */
void WriteColumnInt(uint32_t *p_data, uint8_t column_len, uint8_t column_num)
{
	static uint8_t count_len,buffer[10];
	if(column_num <= NO_OF_COLUMN)
	{
		for(count_len=0;count_len<column_len;count_len++)
		{
			strcpy((char*)buffer,"          ");
			itoa((int)*p_data,(char*)buffer,10);
			WriteInCell(buffer,10,count_len+1,column_num);
			p_data++;
		}
	}
}
