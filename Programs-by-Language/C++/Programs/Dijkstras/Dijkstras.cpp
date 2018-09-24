#include <stdio.h>
#include <iostream>
using namespace std;

const int NODES = 6;
const int ARCS = 9;

//these are the start and end point for the graph traversal
const int START = 0;
const int END = 3;

void FillAdjacencyMatrix( int A[NODES][NODES], int G[ARCS*2+NODES][3] );
//fills the adjacency matrix with the distances between nodes of the graph

void Dijkstras( int A[NODES][NODES] );
//finds the shortest path of the graph, using the adjacency matrix for distances

int main( int argc, char** argv )
{
	int A[NODES][NODES];
	int G[ARCS*2+NODES][3] ;

	//initialize the adjacency matrix with -1
	
	for( int i = 0; i < NODES; i++ )
	{
		for( int j = 0; j < NODES; j++ )
		{
			A[i][j] = -1;
		}
	}
	
	printf( "%s", "Please enter your graph\n" );

	for( int i = 0; i < ARCS*2+NODES; i++ )
	{	
		for( int j = 0; j < 3; j++ )
		{
			cin>>G[i][j];
		}
	}

	//fill A with the adjacencies from G
	FillAdjacencyMatrix( A, G );

	Dijkstras( A );

	return 0;
}

void FillAdjacencyMatrix( int A[NODES][NODES], int G[ARCS*2+NODES][3] )
{
	int pseudoPtr;
	int temp;
	int child;

	for( int n = 0; n < NODES; n++ )
	{
		temp = n;
		while( G[temp][2] != -1 )
		{	
			pseudoPtr = G[temp][2];
			child = G[pseudoPtr][0];
			A[n][child] = G[pseudoPtr][1];
			temp = pseudoPtr;
		}
	}
}

void Dijkstras( int A[NODES][NODES] )
{	
	//this holds the values of the distances between nodes
	int IN[NODES];
	int p;
	int d[NODES];
	int s[NODES];
	int dI;

	//initialize all elements of IN to -1
	for( int i = 0; i < NODES; i++ )
	{
		IN[i] = -1;
	}

	//put START in IN
	IN[START] = START;
	
	//fill the d array with the distances from the start
	for( int i = 0; i < NODES; i++ )
	{
		d[i] = A[START][i];
		s[i] = START;
	}
	
	//distance from START to START is always 0
	d[START] = 0;
	
	//while the end hasnt been reached
	while( IN[END] != END )
	{	
		//set first node not in IN to p
		for( int i = 0; i < NODES; i++ )
		{
			if( IN[i] == -1 )
			{
				p = i;
				dI = d[i];
				break;
			}
		}

		//compare to ensure shortest distance is next p
		for( int i = 0; i < NODES; i++ )
		{
			//if not in IN
			if( d[i] > 0 )
			{
				//if i has the shortest distance, i not in IN
				if( d[i] < d[p] && IN[i] == -1 )
				{
					p = i;
					dI = d[i];
				}
			}
		}

		IN[p] = p;
		
		//find the distances of the nodes not in IN
		for( int i = 1; i < NODES; i++ )
		{
			if( IN[i] == -1 )
			{
				if( ( ( d[i] >  dI + A[p][i] ) || d[i] == -1 ) && A[p][i] > 0 )
				{
					d[i] = dI + A[p][i];
					s[i] = p;
				}
			}
		}
			
	}
	
	int i = END;
	printf( "%s %d %c","The shortest path is: ", END, ' ' );
	while( i != START )
	{
		printf( "%d %c", s[i], ' ' );
		i = s[i];
	}
	cout<<endl;
}

