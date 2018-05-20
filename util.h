#ifndef __UTIL_H_
#define __UTIL_H_

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;

#define MIN_UINT8 	0X00
#define MIN_UINT16 	0X00
#define MIN_UINT32 	0X00

#define MAX_UINT8 	0XFF
#define MAX_UINT16 	0XFFFF
#define MAX_UINT32 	0XFFFFFF

#define CONTROL_BIT(reg,index,command)  ((command) == (0) ? (CLR_BIT(reg,index)):(SET_BIT(reg,index)) )

#define SET_BIT(reg,index)              (reg |= (unsigned char)( 1 << index ))
#define CLR_BIT(reg,index)              (reg &= (unsigned char)( ~ ( 1 << index ) ))
#define TOG_BIT(reg,index)              (reg ^=( 1 << index ))
#define GET_BIT(reg,index)              ( ( reg >> index ) & 0X01 )
#define CONFIG_REG(reg,value)				(reg |= value)

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define BIT0 	0
#define BIT1 	1
#define BIT2 	2
#define BIT3 	3
#define BIT4 	4
#define BIT5 	5
#define BIT6 	6
#define BIT7 	7


#define OUTPUT  0
#define INPUT   1
#define LOW 	0
#define HIGH    1

//IDE dumy delay function
#define DELAY_uS(x) (_delay(x))

// to create a time delay using timer0
/*******************************************************/
//start sandwich
#define StartSandwich(t_delay_us) do{\
                                            SET_TIMER0_ENBLE_BIT;\
                                            UPDTE_TIMER_REG(t_delay_us);\
                                            START_TIMER0;\
                                            }while(0)
/*******************************************************/
//wait sandwich
#define WaitSandwich() do{\
                        while( TIMER_FLAG == 0 ){}\
                        STOP_TIMER0;\
                        }while(0)
/*******************************************************/


void ftoa(float x, char *a);
void itoa(int n, char s[]);
void reverse(char *str);
int strlen(char *s);
void delay(unsigned long x);

#endif
