#include <stdio.h>

void skipGarb();

int main()
{
	int arr[5];

	for( int i = 0; i < 5; i++ )
	{
		scanf( "%d", &arr[i] );
		printf( "%d\n", arr[i] );
		skipGarb();
	}


	
	return 0;
}

void skipGarb()
{
	while( getchar() != '\n' )
	{

	}
}
