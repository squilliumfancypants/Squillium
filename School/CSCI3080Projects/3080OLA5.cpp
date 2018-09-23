#include <iostream>
using namespace std;

//preorder tree traversal - root, lc, mc, rc
void Preorder( int arr[7][3], int root );

//postorder tree traversal - lc, mc, rc, root
void Postorder( int arr[7][3], int root );

//inorder tree traversal - lc, root, mc, rc
void Inorder( int arr[7][3], int root );

int main( int argc, char **argv )
{
	int arr[7][3];
	
	//initialize 2D array
	for( int i = 0; i < 7; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			cin >> arr[i][j];
		}
	}
	
	int root = 1;
	
	//make calls to traversal functions
	Preorder( arr, root );
	cout << endl;
	
	Postorder( arr, root );
	cout << endl;
	
	Inorder( arr, root );
	cout << endl;
	
	return 0;
}

void Preorder( int arr[7][3], int root )
{
	cout << root;
	
	if( arr[root-1][0] > 0 )
	{
		Preorder( arr, arr[root -1][0] );
	}
	
	if( arr[root-1][1] > 0 )
	{
		Preorder( arr, arr[root-1][1] );
	}
	
	if ( arr[root-1][2] > 0 )
	{
		Preorder(arr, arr[root-1][2] );
	}
	
}

void Postorder( int arr[7][3], int root )
{
	
	if( arr[root-1][0] > 0 )
	{
		Postorder( arr, arr[root -1][0] );
	}
	
	if( arr[root-1][1] > 0 )
	{
		Postorder( arr, arr[root-1][1] );
	}
	
	if ( arr[root-1][2] > 0 )
	{
		Postorder(arr, arr[root-1][2] );
	}
	
	cout << root;
}

void Inorder( int arr[7][3], int root )
{
	
	
	if( arr[root-1][0] > 0 )
	{
		Inorder( arr, arr[root -1][0] );
	}
	
	cout << root;
	
	if( arr[root-1][1] > 0 )
	{
		Inorder( arr, arr[root-1][1] );
	}
	
	if ( arr[root-1][2] > 0 )
	{
		Inorder(arr, arr[root-1][2] );
	}
}
