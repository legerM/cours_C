
#include "leds_control.h"
#include<stdio.h>

typedef struct{
	int RValue;
	int GValue;
	int BValue;
}Color;

typedef struct {
	Color table[7][7];

}grille;

const Color red ={255,0,0};
const Color green={0,255,0};
const Color blue={0,0,255};
const Color white={255,255,255};
const Color purple={255,0,255};
const Color yellow={255,255,0};
const Color black={0,0,0};


//void SetLedColor(Color tabline[] , int LEDNum ,Color ledcolor){
//
//
//	if (ledcolor.RValue != 0 && ledcolor.GValue == 0 && ledcolor.BValue == 0)
//	{
//		printf("RED %d\n",tabline[LEDNum].RValue);
//	}
//	else if (ledcolor.RValue == 0 && ledcolor.GValue != 0 && ledcolor.BValue == 0)
//	{
//		printf("Green %d\n",tabline[LEDNum].GValue);
//	}
//	else if (ledcolor.RValue == 0 && ledcolor.GValue == 0 && ledcolor.BValue != 0)
//	{
//		printf("Blue %d\n",tabline[LEDNum].BValue);
//	}
//	else if ((ledcolor.RValue == ledcolor.GValue) && ledcolor.BValue )
//	{
//		printf("White %d\n",tabline[LEDNum].RValue);
//	}
//	else if (ledcolor.RValue !=0 && ledcolor.GValue == 0 && ledcolor.BValue !=0 )
//	{
//		printf("Purple %d\n",tabline[LEDNum].RValue);
//	}
//	else if (ledcolor.RValue !=0 && ledcolor.GValue!=0 && ledcolor.BValue ==0 )
//	{
//		printf("yellow %d\n",tabline[LEDNum].RValue);
//	}
//	else if(ledcolor.RValue ==0 && ledcolor.GValue==0 && ledcolor.BValue ==0) {
//		printf("black %d\n",tabline[LEDNum].RValue);
//
//	}
//}


int main(void){
	Color tabline[7];

//
//	tabline[LED_1].RValue=0; tabline[LED_1].GValue=255; tabline[LED_1].BValue=0;
//
//	tabline[LED_2].RValue= 255; tabline[LED_2].GValue=255; tabline[LED_2].BValue=255;
//
//	tabline[LED_3].RValue= 0; tabline[LED_3].GValue=0; tabline[LED_3].BValue=255;
//
//	tabline[LED_4].RValue= 255; tabline[LED_4].GValue=0; tabline[LED_4].BValue=0;
//
//	tabline[LED_5].RValue= 255; tabline[LED_5].GValue=0; tabline[LED_5].BValue=255;
//
//	tabline[LED_6].RValue= 255; tabline[LED_6].GValue=255; tabline[LED_6].BValue=0;
//
//	tabline[LED_7].RValue= 0; tabline[LED_7].GValue=0; tabline[LED_7].BValue=0;

	void SetLedLine( struct TabLine[], int TabSize){


	}


	setLedColor(1,1,0,255,0);
	sleep(0.1);
	setLedColor(1,2,255,255,255);
	sleep(0.1);
	setLedColor(1,3,0,0,255);
	sleep(0.1);
	setLedColor(1,4,255,0,0);
	sleep(0.1);
	setLedColor(1,5,255,0,255);
	sleep(0.1);
	setLedColor(1,6,255,255,0);
	sleep(0.1);
	setLedColor(1,7,0,0,0);


	return 0;
}