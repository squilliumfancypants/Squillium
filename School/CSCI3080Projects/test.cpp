/*File: CS3080OLA5.cpp
*Author: William Hampton
*Course: CSCI-3080-001
*Lab Number: 5
*Purpose: This program performs a preorder, inorder, and postorder traversal 
* 			of a graph stored as a left-middle-right child array representation.
*			It reads in the number of nodes in the graph, then gets the 
* 			left-middle-right child array representation from the user,
*			then prints the three traversals. 
*Due Date:4/24/2018
*/
#include <iostream>
using namespace std;


void PreOrder(int root, int arr[][3]);

void PostOrder(int root, int arr[][3]);

void InOrder(int root, int arr[][3]);



int main()
{
	int lmr[20][3]={0};
	int root=0;
	int set[20];
	int aSize=0;
	int count[20]={0};
	int nodes=0;
	int parent=0;
	
	
	cout<<"Enter the number of nodes: ";
	cin>>nodes;
	
	for (int i=0; i<nodes; i++)
	{
		for (int j=0; j<3; j++)
		{
			cin>>lmr[i][j];
		}
	}
	
	PreOrder(root, lmr);
	
	cout<<"The Preorder Traversal is: ";
	for (int i=0; i<aSize; i++)
		cout<<set[i]<<" ";
	cout<<endl;
	
	root=0;
	
	aSize=0;
	
	for (int y=0; y<20; y++)
	{
		set[y]=0;
		count[y]=0;
	}
	
	PostOrder(root, lmr);
	
	set[aSize]=0;
	set[aSize]++;
	
	cout<<"The Postorder Traversal is: ";
	
	for (int i=0; i<aSize; i++)
		cout<<set[i]<<" ";
	cout<<endl;
	
	for (int i=0; i<nodes; i++)
		cout<<i<<" has a count of: "<<count[i]<<endl;
	cout<<endl;
	
	root=0;
	
	aSize=0;
	
	for (int y=0; y<20; y++)
	{
		set[y]=0;
		count[y]=0;
	}
	
	InOrder(root, lmr);
	
	cout<<"The Inorder Traversal is: ";
	
	for (int i=0; i<aSize; i++)
		cout<<set[i]<<" ";
	cout<<endl;
	
	for (int i=0; i<nodes; i++)
		cout<<i<<" has a count of: "<<count[i]<<endl;
	cout<<endl;
	
	return 0;
}




void PreOrder(int root, int arr[][3])
{
	int LC=0, MC=0, RC=0;
	for (int j=0; j<3; j++)
	{
		if (arr[root][j]>0 && j==0)
			LC=arr[root][j];
			
		else if (arr[root][j]>0 && j==1)
			RC=arr[root][j];
			
		else if (arr[root][j]>0 && j==2)
			RC=arr[root][j];
	}
	while(root==0)
	{
		cout<<root<<endl;
		PreOrder(LC, arr);
		PreOrder(RC, arr);
	}
}

void PostOrder(int root, int arr[][3])
{
	int LC=0, MC=0, RC=0;
	for (int j=0; j<3; j++)
	{
		if (arr[root][j]>0 && j==0)
			LC=arr[root][j];
			
		else if (arr[root][j]>0 && j==1)
			RC=arr[root][j];
			
		else if (arr[root][j]>0 && j==2)
			RC=arr[root][j];
	}
	while(root==0)
	{
		PostOrder(LC, arr);
		PostOrder(RC, arr);
		cout<<root<<endl;
	}
}

void InOrder(int root, int arr[][3])
{
	int LC=0, MC=0, RC=0;
	for (int j=0; j<3; j++)
	{
		if (arr[root][j]>0 && j==0)
			LC=arr[root][j];
			
		else if (arr[root][j]>0 && j==1)
			RC=arr[root][j];
			
		else if (arr[root][j]>0 && j==2)
			RC=arr[root][j];
	}
	while(root==0)
	{
		InOrder(LC, arr);
		cout<<root<<endl;
		InOrder(RC, arr);
		
	}
}

