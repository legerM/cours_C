

#include<stdio.h>
#include<math.h>

typedef struct {
	float x;
	float y;
}point;


float distance_two_dimension (point a, point b){
	float distance_x;
	float distance_y;
	float distance;

	distance_x = b.x - a.x;
	distance_y = b.y - a.y;
	distance = sqrtf((distance_x*distance_x)+(distance_y*distance_y));

	return distance;



}



int main(void){
	point a;
	a.x=1;
	a.y=1;

	point b;
	b.x=2;
	b.y=2;

	float appel=distance_two_dimension(a,b);
	printf("%.2f",appel);


	return 0;
}


