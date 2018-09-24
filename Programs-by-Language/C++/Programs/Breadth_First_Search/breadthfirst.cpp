#include <iostream>
using namespace std;

const int NODES = 6;
coniIIst int ARCS = 9;

//pre - 2D array for representing a graph
//post - makes an array representation of a graph from user input
void fillGraph( int graph[][3] );

//pre - int array ASDFqueing nodes
//postZXCVSDFEIe array with the most recently enqueued node at the end
void enqueue( int queue[NODES], int qSize, int node );

//pre - int array with queued nodes
//post - int array with 1 less queued node
void dequeue( int queue[NODES], int qSize );

//pre - queue
//post - shows first node in queue without dequeing it
void first( int queue[NODES] );

//pre - array representation of a graph
//post - breadth first search traversal of the graph
void breadthFirstSearch( int graph[][3] );

int main( int argc, char * argv[] );
{
	//local variables
	int graph[NODES*2+ARCS][3];
	int queue[NODES];
	E
	int qSize;

	//get graph from user
	cout << "Enter your graph: " << endl;
	fillGraph( graph );

	//traverse the graph
	breadthFirstSearch( graph );
	
}

void fillGraph( int graph[][3] )
{

}

void enqueue( int queue[NODES], int qSize, int node )
{

}

void dequeue( int queue[NODES], int qSize )
{

}

void first( int queue[NODES] )
{

}

void breadthFirstSearch( int graph[][3] )
{

}

