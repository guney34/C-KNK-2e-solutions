#include <stdio.h>
#ifndef M_PI
#define M_PI 3.141592f
#endif
#define RADIUS 10.0f

int main(void)
{
	float vol = (4.0f / 3.0f) * M_PI * RADIUS*RADIUS*RADIUS;
	printf("Volume = %f", vol);
}