/*File: CS3080OLA2.cpp
 *Author: William Hampton
 *Course: CSCI-3080-001
 *Lab Number: 2
 *Purpose: This program gets 2 matrices from the user, 
 *			and performs the user's choice of operation
 * 			on the two matrices, if possible.
 *Due Date:2/6/2018
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	
	//initialize variables and arrays
	//save the dimensions as arrays for fun
	int arrA[10][10],rowA,colA,arrB[10][10],rowB,colB,arrC[10][10];
	char space;
	string opChoice;
	
	cout<<"Enter the number of rows and columns of matrix A: "<<endl;
	//r1=number of rows, colA=number of columns
	cin>>rowA>>colA;
	cin.get(space);
	cout<<endl<<"Enter matrix A: "<<endl;
	for(int i=0;i<rowA;i++)
		{
			for(int j=0;j<colA;j++)
				{
					cin>>arrA[i][j];
					cin.get(space);
				}
		}
	cout<<endl;
	//get dimensions for matrix 2
	cout<<"Enter the number of rows and columns of matrix B: "<<endl;
	//rowB=number of rows, colB=number of columns
	cin>>rowB>>colB;
	cin.get(space);
	cout<<endl<<"Enter matrix B: "<<endl;
	//
	for(int i=0;i<rowB;i++)
		{
			for(int j=0;j<colB;j++)
				{
					cin>>arrB[i][j];
					cin.get(space);
				}
		}
	cout<<endl;
	cout<<"You can perform the following operations on your matrices: "<<endl;
	cout<<"To add, enter [A]. To subtract, enter [S]. To Multiply, enter [M]."<<endl;
	cin>>opChoice;
	cout<<endl;
	if (opChoice=="A")
		{
			if (rowA==rowB && colA==colB)
			{
				for (int i=0;i<rowA;i++)
				{
					for(int j=0;j<colA;j++)
						{
							arrC[i][j]=arrA[i][j]+arrB[i][j];
						}
				}
			}
			else
				{
					cout<<"Error. The dimensions of matrix A must equal the dimensions of matrix B."<<endl;
					cout<<"Ending program."<<endl;
					return 0;
				}
		}
	else if (opChoice=="S")
		{
			if (rowA==rowB && colA==colB)
			{
				for (int i=0;i<rowA;i++)
				{
					for(int j=0;j<colA;j++)
						{
							arrC[i][j]=arrA[i][j]-arrB[i][j];
						}
				}
			}
			else
				{
					cout<<"Error. The dimensions of matrix A must equal the dimensions of matrix B."<<endl;
					cout<<"Ending program."<<endl;
					return 0;
				}
		}
	else if (opChoice=="M")
		{
			if (colA==rowB)
			{
				for (int i=0;i<rowA;i++)
				{
					for (int j=0;j<colB;j++)
						{
							for (int k=0;k<colA;k++)
							{
								arrC[i][j]+=arrA[j][k]*arrB[k][j];
							}
						}
				}
			}
			else
				{
					cout<<"Error. The number of columns in matrix A must equal the "<<endl
						<<"number of rows in matrix B."<<endl<<"Ending program.";
					return 0;
				}
		}
	else
		{
			cout<<"Invalid entry."<<endl<<"Closing program."<<endl;
		}
	for(int i=0;i<rowA;i++)
		{
			for(int j=0;j<colB;j++)
				{
					if (arrC[i][j]<0)
					{
						cout<<arrC[i][j];
					}
					else
					{
						cout<<" "<<arrC[i][j];
					}
				}
			cout<<endl;
		}
	return 0;
}