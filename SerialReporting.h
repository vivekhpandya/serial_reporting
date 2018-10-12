/*
 * SerialReporting.h
 *
 *  Created on: Oct 10, 2018
 *      Author: vivekhpandya
 */
/* >>>>>>>>>>>> SOME STANDARD DEFINITIONS <<<<<<<<<<<<< */
#define concat(a, b) a##b
#define stringOf(num)	#num

/**
 * @Description : 
 */
#define DOWN_CSR	uint8_t down_csr[3] 	= {0x1b,0x5b,0x42}
#define UP_CSR		uint8_t up_csr[3] 		= {0x1b,0x5b,0x41}
#define LEFT_CSR	uint8_t left_csr[3] 	= {0x4b,0x5b,0x44}
#define RIGHT_CSR	uint8_t right_csr[3] 	= {0x4b,0x5b,0x43}

/* >>>>>>>>>>>> <<<<<<<<<<<<< */
#define NO_OF_COLUMN		3	//Max is limited to 6
#define NO_OF_ROW			30

#define NO_OF_COMA		NO_OF_COLUMN+1		//As per CSV standard
#define COMA_LEN		1
#define CR_LF_LEN		2				//As per CSV standard

#define NULL_WIDTH		0
#define WIDTH_COLUMN_0		NULL_WIDTH

#if NO_OF_COLUMN >= 1
#define WIDTH_COLUMN_1		10	//Total no of characters
#else
#define WIDTH_COLUMN_1		NULL_WIDTH
#endif

#if NO_OF_COLUMN >= 2
#define WIDTH_COLUMN_2		7	//Total no of characters
#else
#define WIDTH_COLUMN_2		NULL_WIDTH
#endif

#if NO_OF_COLUMN >= 3
#define WIDTH_COLUMN_3		5	//Total no of characters
#else
#define WIDTH_COLUMN_3		NULL_WIDTH
#endif

#if NO_OF_COLUMN >= 4
#define WIDTH_COLUMN_4		6	//Total no of characters
#else
#define WIDTH_COLUMN_4		NULL_WIDTH
#endif

#if NO_OF_COLUMN >= 5
#define WIDTH_COLUMN_5		6	//Total no of characters
#else
#define WIDTH_COLUMN_5		NULL_WIDTH
#endif

#if NO_OF_COLUMN >= 6
#define WIDTH_COLUMN_6		6	//Total no of characters
#else
#define WIDTH_COLUMN_6		NULL_WIDTH
#endif

#define GET_WIDTH_COLUMN(no)	(no == 1 ? WIDTH_COLUMN_1 : (no == 2 ? WIDTH_COLUMN_2 : (no == 3 ? WIDTH_COLUMN_3 : \
		(no == 4 ? WIDTH_COLUMN_4 : (no == 5 ? WIDTH_COLUMN_5 : (no == 6 ? WIDTH_COLUMN_6 : NULL_WIDTH))))))

#define LOCATION_COLUMN_(no)	GET_WIDTH_COLUMN(no-1) + (COMA_LEN * (no)) + 1

#define TOTAL_WIDTH		WIDTH_COLUMN_1 + WIDTH_COLUMN_2 + WIDTH_COLUMN_3 + WIDTH_COLUMN_4 + WIDTH_COLUMN_5 + WIDTH_COLUMN_6 \
						+ NO_OF_COMA + CR_LF_LEN
#define TOTAL_LENGTH	NO_OF_ROW

#define ARRAY_LENGTH	(TOTAL_WIDTH) * (TOTAL_LENGTH)

#ifndef SERIALREPORTING_H_
#define SERIALREPORTING_H_

/* >>>>>>>>>> VARIABLE DEFINITIONS <<<<<<<<< */
uint8_t printing_array[TOTAL_LENGTH][TOTAL_WIDTH] = \
  /*Fill it without violating above range definitions - NEVER USE TAB*/
  /*Don't consider comma in matching length*/
{	",ABCDEFG1  ,12.345 ,unit ;\r\n",	//1
	",ABCDEFG2  ,12.345 ,unit ;\r\n",	//2
	",ABCDEFG3  ,12.345 ,unit ;\r\n",	//3
	",ABCDEFG4  ,12.345 ,unit ;\r\n",	//4
	",ABCDEFG5  ,12.345 ,unit ;\r\n",	//5
	",ABCDEFG6  ,12.345 ,unit ;\r\n",	//6
	",ABCDEFG7  ,12.345 ,unit ;\r\n",	//7
	",ABCDEFG8  ,12.345 ,unit ;\r\n",	//8
	",ABCDEFG9  ,12.345 ,unit ;\r\n",	//9
	",ABCDEFG10 ,12.345 ,unit ;\r\n",	//10
	",ABCDEFG11 ,12.345 ,unit ;\r\n",	//11
	",ABCDEFG12 ,12.345 ,unit ;\r\n",	//12
	",ABCDEFG13 ,12.345 ,unit ;\r\n",	//13
	",ABCDEFG14 ,12.345 ,unit ;\r\n",	//14
	",ABCDEFG15 ,12.345 ,unit ;\r\n",	//15
	",ABCDEFG16 ,12.345 ,unit ;\r\n",	//16
	",ABCDEFG17 ,12.345 ,unit ;\r\n",	//17
	",ABCDEFG18 ,12.345 ,unit ;\r\n",	//18
	",ABCDEFG19 ,12.345 ,unit ;\r\n",	//19
	",ABCDEFG20 ,12.345 ,unit ;\r\n",	//20
	",ABCDEFG21 ,12.345 ,unit ;\r\n",	//21
	",ABCDEFG22 ,12.345 ,unit ;\r\n",	//22
	",ABCDEFG23 ,12.345 ,unit ;\r\n",	//23
	",ABCDEFG24 ,12.345 ,unit ;\r\n",	//24
	",ABCDEFG25 ,12.345 ,unit ;\r\n",	//25
	",ABCDEFG26 ,12.345 ,unit ;\r\n",	//26
	",ABCDEFG27 ,12.345 ,unit ;\r\n",	//27
	",ABCDEFG28 ,12.345 ,unit ;\r\n",	//28
	",ABCDEFG29 ,123.45 ,uint ;\r\n",	//29
	",ABCDEFG30 ,12.34  ,uint ;\r\n",	//30
};

/* >>>>>>>>>> FUCNTION DECLAIRATIONS <<<<<<<<< */
void WriteInCell(uint8_t *p_data, uint8_t len, uint8_t column_num, uint8_t row_num);
void printSerial(UART_HandleTypeDef *huart);
void WriteColumnInt(uint32_t *, uint8_t , uint8_t );

#endif /* SERIALREPORTING_H_ */

#ifdef	SERIALREPORTING_H_

/* >>>>>>>>>> VARIABLE IMPORTING <<<<<<<<< */
extern uint8_t printing_array[TOTAL_LENGTH][TOTAL_WIDTH];

/* >>>>>>>>>> FUCNTION DECLAIRATIONS <<<<<<<<< */
extern void WriteInCell(uint8_t *p_data, uint8_t len, uint8_t column_num, uint8_t row_num);
extern void printSerial(UART_HandleTypeDef *huart);
extern void WriteColumnInt(uint32_t *, uint8_t , uint8_t );

#endif
