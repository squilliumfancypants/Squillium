/*File: CS3080OLA4.cpp
 *Author: William Hampton
 *Course: CSCI-3080-001
 *Lab Number: 4
 *Purpose: This program creates an adjacency matrix from a user-entered array-pointer
 *			representation of a graph, then print it.
 *			The program prints all isolated nodes.
 * 			The program prints the degree of each node.
 * 			The program prints all nodes adjacent to each node.
 *Due Date:4/12/2018
 */
#include <iostream>
using namespace std;

int main()
{
	int adjacencyMatrix[20][20]={0};		//initialize all elements of a 20 x 20 matrix to 0
	int arrayPointer[20][2]={0};		//this holds the user-entered values of the array-pointer
									//representation of the graph. initialized to 0
	int numberOfRows;		//stores the value of the number of rows of the array-pointer representation of the graph
	int numberOfNodes;		//store the value of the number of nodes in the users graph
	int node, pointer;		//stores the temporary values of nodes and their pointers used in creating the adjacency matrix
	int sum;		//used to check for isolated nodes by adding the sum of the arcs of the rows
	int commaCount;		//used for punctution during output
	int dwCount=0;		//used to keep track of number of iterrations of do-while loops
	
	cout<<"Please enter the number of nodes in the graph: ";
	cin>>numberOfNodes;
	cout<<endl;
	cout<<"Please enter the number of rows in the matrix: ";
	//this do-while loop ensures user input is in bounds
	do
	{
		if (dwCount>0)
		{
			cout<<endl<<"Please enter a number that is between 1 and 20, inclusive "<<endl
				<<"and greater than or equal to the number of nodes: "<<endl;
		}
		cin>>numberOfRows;
		dwCount++;
	}while(numberOfRows<1||numberOfRows<numberOfNodes||numberOfRows>20);
	cout<<endl;
	cout<<"Please enter the array-pointer representation of the graph:"<<endl;
	
	//each row of the arry-pointer representation has two available columns.
	//the first column (0) is the column that holds the value of the node that the "pointer" 
	//points to. 
	//the second column(1) is the column taht holds the value of the "pointer" itself
	//get the value of the array-pointer representation of the graph from the user
	for (int i=0; i<numberOfRows; i++)
	{
		for (int j=0; j<2; j++)
			cin>>arrayPointer[i][j];
	}
	cout<<endl;

	//create the adjacency matrix by traversing the matrix using the pointer, instead of 
	//a usual column variable
	for (int i=0; i<numberOfNodes; i++)
	{
		pointer=i;
		if (arrayPointer[i][1]>0)
		{
			//this loop assigns a 1 to the adjacency matrix for any adjacencies
			//the loop terminates when the pointer in its column is 0
			do
			{
				pointer=(arrayPointer[pointer][1])-1;
				node=(arrayPointer[pointer][0])-1;
				adjacencyMatrix[i][node]=1;
			}
			while(arrayPointer[pointer][1]>0);
		}
	}
	//display the adjacency matrix
	cout<<"This is the adjacency matrix made from your input: "<<endl<<endl;
	for (int i=0; i<numberOfNodes; i++)
	{
		for (int j=0; j<numberOfNodes; j++)
		{
			cout<<adjacencyMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	//output the isolated nodes
	cout<<"The isolated nodes are: ";
	
	//add take the sum of all of the elements in a row. if sum of a row is 0, the node associated
	//with the row is an isolated node
	for (int i=0; i<numberOfNodes; i++)
	{
		sum=0;
		for (int j=0; j<numberOfNodes; j++)
		{
			sum+=adjacencyMatrix[i][j];
		}
		
		if (sum==0)
			cout<<i+1<<", ";
	}
	cout<<endl<<endl;
	
	//The program prints the degree of each node.
	//very similar to above. take the sum of all of the elements
	//in a row. the result is the degree of the node associated with the row
	
	cout<<"The degrees of the nodes are as follows: "<<endl;
	
	//sum each row seperately. the sum of the row is the degree of the node.
	for (int i=0; i<numberOfNodes; i++)
	{
		sum=0;
		for (int j=0; j<numberOfNodes; j++)
		{
			if (i==j)
				sum+=(adjacencyMatrix[i][j]*2);
			
			else
				sum+=adjacencyMatrix[i][j];
		}
			
		cout<<i+1<<"/"<<sum<<endl;
	}
	cout<<endl;
	
	//The program prints all nodes adjacent to each node.
	
	cout<<"The node adjacencies, in the form *node: adjacent nodes* are: "<<endl;
	
	//display the adjacencies by checking all the adjacency matrix indeces against the 
	//current iterrations row value
	for (int i=0; i<numberOfNodes; i++)
	{
		//the commaCount variable seen here governs whether to use a comma, or not
		commaCount=0;
		cout<<i+1<<":";

		for (int j=0; j<numberOfNodes; j++)
		{
			//the comma count is included again here for formatting
			if ((adjacencyMatrix[i][j]!=0) && (commaCount==0))
			{
				cout<<" "<<j+1;
				commaCount++;
			}
			else if (adjacencyMatrix[i][j]!=0)
				cout<<", "<<j+1;
		}
		cout<<endl;
	}
	
	return 0;
}