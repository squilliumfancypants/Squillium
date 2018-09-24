#include <stdio.h>

int GCD(int x, int y);

int main(int argc, char **argv)
{
	int x,y;
	x = 36;
	y = 12;
	
	printf("The GCD is %d",GCD(x,y));
	
	
	return 0;
}

int GCD(int x, int y){
	int r;
	int temp;
	
	r = x % y;
	
	while (r!=0){
		temp = r;
		r = y % r;
		y = temp;
	}
	
	return y;
}