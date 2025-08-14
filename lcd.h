#include<LPC17xx.h>
#define RS (1<<10)
#define EN (1<<11)
#define DATA (0xFF<<15)


void delay(unsigned int i);
void led_config(void);
void led_cmd(unsigned char c);
void led_data(unsigned char d);
 void led_str(unsigned char str[20]);
void led_num(unsigned int num);
void left(unsigned int I);
  void right(unsigned int r);