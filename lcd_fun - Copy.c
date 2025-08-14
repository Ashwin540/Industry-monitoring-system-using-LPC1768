   #include<LPC17xx.h>
   #include "lcd.h"

   void led_config(void){

	LPC_GPIO0->FIODIR=RS|EN|DATA;
	led_cmd(0x38);
	led_cmd(0x0E);
	led_cmd(0x01);
	led_cmd(0x80);
	led_cmd(0xc0);

   }


   void	led_cmd(unsigned char c){

	   LPC_GPIO0->FIOCLR=DATA;
	   LPC_GPIO0->FIOSET=(c<<15);
	   LPC_GPIO0->FIOCLR=RS;
	   LPC_GPIO0->FIOSET=EN;
	   delay(10);
	   LPC_GPIO0->FIOCLR=EN;
   }


   void led_data(unsigned char d){

	  LPC_GPIO0->FIOCLR=DATA;
	  LPC_GPIO0->FIOSET=(d<<15);
	  LPC_GPIO0->FIOSET=RS;
	  LPC_GPIO0->FIOSET=EN;
	  delay(10);
	  LPC_GPIO0->FIOCLR=EN;


   }


   void led_str(unsigned char str[20]){

	int i;
	for(i=0;str[i]!='\0';i++){

	   led_data(str[i]);
	}


   }


   void led_num(unsigned int num){
	 if(num){
		 led_num(num/10);
		 led_data(num%10+0x30);
	 }

   }


   void delay(unsigned int i){

	  int j,k;
	  for(j=0;j<i;j++)
	     for(k=0;k<3000;k++);


   }


   void left(unsigned int I){
		  int i;
		  for(i=0;i<=I;i++){
		   led_cmd(0x18);
		   delay(100);
		  }
   }


   void right(unsigned int r){
	int i;
	for(i=0;i<=r;i++){
	 led_cmd(0x1c);
	 delay(100);
	}
   }