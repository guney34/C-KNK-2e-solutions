#include <stdio.h>
#ifndef M_PI
#define M_PI 3.141592f
#endif


int main(void)
{
	float radius;
	printf("Enter sphere radius: ");
	scanf("%f", &radius);
	float vol = (4.0f / 3.0f) * M_PI * radius * radius * radius;
	printf("Sphere volume = %f", vol);
}