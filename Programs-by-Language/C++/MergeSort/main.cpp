#include <stdio.h>

void BottomUpMergeSort( int A[10], int B[10], int n );
//takes in an array of values, and sorts the values

void BottomUpMerge( int A[10], int iLeft, int iRight, int iEnd, int B[10] );
//fills array B with runs of length 2 * width

void CopyArray( int B[10], int A[10], int n );

//------------------------------------ utility functions ------------------------------------
int min( int a, int b )
{
	int val;
	
	if( a < b)
	{
		val = a;
	}
	
	else if( b < a )
	{
		val = b;
	}
	
	else
	{
		val = a;
	}
	
	return val;
}

int main(int argc, char **argv)
{
	int A[10] = { 9, 7, 5, 1, 0, 2, 4, 3, 8, 6 };
	int B[10];
	int aSize = 10;
	
	BottomUpMergeSort( A, B, aSize );
	
	for( int i = 0; i < aSize; i++ )
	{
		printf( "%d", B[i] );
	}
	putchar('\n');
	
	return 0;
}

void BottomUpMergeSort( int A[10], int B[10], int n )
{
	//each 1-element run in A is already "sorted"
	
	//make successively longer sorted runs of length
	//2, 4, 8, 16... until whole array is sorted
	for( int width = 1; width < n; width = 2 * width )
	{
		//array A is full of runs of length width
		for( int i = 0; i < n; i = i + 2 * width )
		{
			//merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B
			//or copy A[i:n-1] to B[] ( if( i + width >= n) )
			BottomUpMerge( A, i, min(i+width, n), min(i+2*width, n), B );
		}
		//now work array B is full of runs of length 2*width
		
		//copy array B to array A for next iteration
		//a more efficient implementation would swap the roles of A and B
		CopyArray( B, A, n );
		
		//now array A is full of runs of length 2*width
	}
}

void BottomUpMerge( int A[], int iLeft, int iRight, int iEnd, int B[] )
//left run is A[iLeft:iRight-1], right run is A[iRight:iEnd-1
{
	int i = iLeft;
	int j = iRight;
	
	//while there are elements in the left or right runs...
	for( int k = iLeft; k < iEnd; k++ )
	{
		//if left run head exists and is <= existing right run head
		if( i < iRight && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i += 1;
		}
		
		else
		{
			B[k] = A[j];
			j += 1;
		}
	}
}

void CopyArray( int B[], int A[], int n )
{
	for( int i = 0; i < n; i++)
	{
		A[i] = B[i];
	}
}