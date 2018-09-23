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

int addition(int a, int b)
{
	//this function adds the element of Matrix A to the element of Matrix B, if possible, 
	//and returns the resulting element as an int.
	int McElement;
	
	McElement=a+b;
	return McElement;
}

int subtraction(int a, int b)
{
	//this function subtracts the element of Matrix A to the element of Matrix B, if possible, 
	//and returns the resulting element as an int.
	int McElement;
	
	McElement=a-b;
	return McElement;
}

int multiply(int a, int b)
{
	//this function multiplies the element of Matrix A to the element of Matrix B, if possible, 
	//and returns the resulting element as an int.
	int McElement;
	
	McElement=a*b;
	return McElement;
}

int main()
{
	
	//initialize variables and arrays
	int arrA[10][10],rowA,colA,arrB[10][10],rowB,colB,arrC[10][10],MaElement,MbElement;
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
	
	//get dimensions for matrix B
	cout<<"Enter the number of rows and columns of matrix B: "<<endl;
	//rowB=number of rows, colB=number of columns
	cin>>rowB>>colB;
	cin.get(space);
	cout<<endl<<"Enter matrix B: "<<endl;
	//get elements in matrix B
	for(int i=0;i<rowB;i++)
		{
			for(int j=0;j<colB;j++)
				{
					cin>>arrB[i][j];
					cin.get(space);
				}
		}
	cout<<endl;
	
	//get the users choice of operation
	cout<<"You can perform the following operations on your matrices: "<<endl;
	cout<<"To add, enter [A]. To subtract, enter [S]. To Multiply, enter [M]."<<endl;
	cin>>opChoice;
	cout<<endl;
	
	if (opChoice=="A")
		{
			//validate choice of addition. perform operation if valid. else print error.
			if (rowA==rowB && colA==colB)
			{
				for (int i=0;i<rowA;i++)
				{
					for(int j=0;j<colA;j++)
						{
							//give variables the value of Matrix A and B
							//pass into addition function
							//arrC[i][j]=arrA[i][j]+arrB[i][j];
							arrC[i][j]=addition(arrA[i][j], arrB[i][j]);
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
			//validate choice of subtraction. perform operation if valid. else print error.
			if (rowA==rowB && colA==colB)
			{
				for (int i=0;i<rowA;i++)
				{
					for(int j=0;j<colA;j++)
						{
							//arrC[i][j]=arrA[i][j]+arrB[i][j];
							arrC[i][j]=subtraction(arrA[i][j], arrB[i][j]);
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
			//validate choice of multiplication. perform operation if valid. else print error
			if (colA==rowB)
			{
				//choice is validated, initialize arrC to 0
				for (int i=0;i<rowA;i++)
					{
						for (int j=0;j<colB;j++)
						{
							arrC[i][j]=0;
						}
					}	
				for (int i=0;i<rowA;i++)
				{
					for (int j=0;j<colB;j++)
						{
							for (int k=0;k<colA;k++)
							{
								arrC[i][j]+=multiply(arrA[i][k], arrB[k][j]);
							}
						}
				}
			}
			else
				{
					cout<<"Error. The number of columns in matrix A must equal the "<<endl
						<<"number of rows in matrix B."<<endl<<"Ending program."<<endl;
					return 0;
				}
		}
	//end program if no valid operation choice is entered
	else
		{
			cout<<"Invalid entry."<<endl<<"Ending program."<<endl;
		}
	//print the result of the selected operation, matrix C
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