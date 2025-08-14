//industry monitoring system

#include<lpc17xx.h>
#include "lcd.h"
#include "lcd_fun.c"
#define IR (1<<1)
#define IN1 (1<<25)
#define IN2 (1<<26)
#define buzzer (1<<27)
#define gas (1<<4)
#define fire (1<<9)
#define relay (1<<28)

void helmetcheck();
void firecheck();
void gascheck();
void TEMPERATURE_MONITORING();


void main(){

 led_config();
 LPC_SC->PCONP|=(1<<12);	 //SC-SYSTEM CONTROL,ENABLE POWER ADC
 LPC_SC->PCLKSEL0|=(1<<25)|(1<<24);//ENABLE CLK FOR ADC
 LPC_PINCON->PINSEL1|=(1<<18);//CONFIG P0.25 OF AIN2 AD0.2
 LPC_ADC->ADCR=(1<<2)|(4<<8)|(1<<16)|(1<<21);
 LPC_GPIO1->FIODIR &= ~IR;
 LPC_GPIO1->FIODIR &= ~fire;
 LPC_GPIO1->FIODIR &= ~gas;

 LPC_GPIO1->FIODIR|=IN1;
 LPC_GPIO1->FIODIR|=IN2;
 LPC_GPIO1->FIODIR|=relay;
  LPC_GPIO1->FIODIR|=buzzer;

   LPC_GPIO1->FIOCLR =buzzer;
   LPC_GPIO1->FIOCLR =relay;

   led_cmd(0x01);
   led_cmd(0x80);
   led_str("INDUSTRIAL MONITOR");
   led_cmd(0xc0);
   led_str("SYSTEM");
   delay(1000);


   while(1){
	 
	  helmetcheck();
	   firecheck();
	   gascheck();
	    TEMPERATURE_MONITORING();

   }
   }


	void   helmetcheck(){
	  	
		if((LPC_GPIO1->FIOPIN&IR)==0){
			   led_cmd(0x01);
			   led_cmd(0x80);
			   led_str("helmet detected");
			   LPC_GPIO1->FIOSET=IN1;
			   LPC_GPIO1->FIOCLR=IN2;
			   
			   delay(1000);

			   LPC_GPIO1->FIOCLR=IN1;
			   LPC_GPIO1->FIOCLR=IN2;

			   delay(1000);

			   LPC_GPIO1->FIOCLR=IN1;
			   LPC_GPIO1->FIOSET=IN2;

			   delay(1000);

			   LPC_GPIO1->FIOCLR=IN1;
			   LPC_GPIO1->FIOCLR=IN2;

			   delay(1000);

		}



		else{

		 	led_cmd(0x01);
			led_cmd(0x80);

			led_str("no helmet");
			 delay(1000);
			LPC_GPIO1->FIOCLR=IN1;
			LPC_GPIO1->FIOCLR=IN2;
			delay(1000);

		}


	}



	void firecheck(){

	 	if((LPC_GPIO1->FIOPIN & fire)==0){

		 led_cmd(0x01);
		 led_cmd(0x80);
		 led_str("fire detected");
		 LPC_GPIO1->FIOSET=buzzer;
		 delay(1000);
		 LPC_GPIO1->FIOCLR=buzzer;
		 delay(1000);


		}


		 else{

		  	led_cmd(0x01);
			led_cmd(0x80);

			led_str("no fire");
			LPC_GPIO1->FIOCLR=buzzer;
			delay(1000);

		 }

	}


	void gascheck(){

	 	if((LPC_GPIO1->FIOPIN&gas)==0){
		 	led_cmd(0x01);
			led_cmd(0x80);
			led_str("gas detected ");

			LPC_GPIO1->FIOSET=buzzer;
			delay(1000);
			LPC_GPIO1->FIOCLR=buzzer;
			delay(1000);


		}


		else{
		   led_cmd(0x01);
		   led_cmd(0x80);

		   led_str("NO GAS");

		   	LPC_GPIO1->FIOCLR=buzzer;
			delay(1000);
		   
		}


	}


	void  TEMPERATURE_MONITORING(){

	 	unsigned int adc_value;

		while(!(LPC_ADC->ADGDR&(1<<31)));	//CHECKING DONE BIT SET OR NOT USING POLLING
		//STATEMENT
		adc_value=(LPC_ADC->ADDR2&(0XFFF<<4)); //READ THE DIGITAL VALUE TO ANY VARIABLE 

		adc_value=adc_value>>4;//right shift by 4 to get lsb

		adc_value=adc_value/13.6;//converting raw temperature to degree celcious
		led_cmd(0x01);
		led_cmd(0x80);
		led_str("TEMP");
		led_cmd(0xc0);
		led_cmd(adc_value);	  //display temp
		led_data(0xDF);
		led_str("c");
		delay(1000);

		if(adc_value > 27){

		 	led_cmd(0x01);
			led_str("more temperature");
			LPC_GPIO1->FIOSET=buzzer;
			LPC_GPIO1->FIOSET=relay;
			delay(100);
		}

		else {

		 led_cmd(0x01);
		 led_str("normal temperature");
		 LPC_GPIO1->FIOCLR=relay;
		 delay(1000);

		}


	}







 



