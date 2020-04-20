

#include<stdio.h>

typedef struct{
	int RValue;
	int GValue;
	int BValue;
}Color;


void SetLedColor( Color ledcolor){


	if (ledcolor.RValue != 0 && ledcolor.GValue == 0 && ledcolor.BValue == 0)
	{
		printf("RED %d\n",ledcolor.RValue);
	}
	else if (ledcolor.RValue == 0 && ledcolor.GValue != 0 && ledcolor.BValue == 0)
	{
		printf("Green %d\n",ledcolor.GValue);
	}
	else if (ledcolor.RValue == 0 && ledcolor.GValue == 0 && ledcolor.BValue != 0)
	{
		printf("Blue %d\n",ledcolor.BValue);
	}
	else if ((ledcolor.RValue == ledcolor.GValue) && ledcolor.BValue )
	{
		printf("White %d\n",ledcolor.RValue);
	}
	else if (ledcolor.RValue !=0 && ledcolor.GValue == 0 && ledcolor.BValue !=0 )
	{
		printf("Purple %d\n",ledcolor.RValue);
	}
	else if (ledcolor.RValue !=0 && ledcolor.GValue!=0 && ledcolor.BValue ==0 )
	{
		printf("yellow %d\n",ledcolor.RValue);
	}
	else if(ledcolor.RValue ==0 && ledcolor.GValue==0 && ledcolor.BValue ==0) {
		printf("black %d\n",ledcolor.RValue);

	}
}


int main(void){


	Color red ={255,0,0};
	Color green={0,255,0};
	Color blue={0,0,255};
	Color white={255,255,255};
	Color purple={255,0,255};
	Color yellow={255,255,0};
	Color black={0,0,0};



	SetLedColor(yellow);
	SetLedColor(purple);
	SetLedColor(white);
	SetLedColor(red);
	SetLedColor(green);
	SetLedColor(blue);
	SetLedColor(black);


	return 0;
}
