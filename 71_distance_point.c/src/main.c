#include<stdio.h>
#include<math.h>

int main(void){
	double x1;
	double x2;
	double y1;
	double y2;
	double distance_x;
	double distance_y;
	double distance;


	printf("veuillez entrer deux coordonnées\n");
	scanf("%lf %lf",&x1,&y1);
	printf("veuillez entrer encore deux autres coordonnnées\n");
	scanf("%lf %lf",&x2,&y2);




	distance_x = x2 - x1;
	distance_y = y2 - y1;

	distance = sqrt((distance_x*distance_x)+(distance_y*distance_y));
	printf("la distance est de %10.2lf",distance);






	return 0;
}
