/*File: CS3080OLA3.cpp
 *Author: William Hampton
 *Course: CSCI-3080-001
 *Lab Number: 3
 *Purpose: This program gets a nxn matrix from the user, and performs Gaussian elimination
 * 			to find the identity matrix of the user's matrix.
 *Due Date:3/1/2018
 */
 #include <iostream>
 using namespace std;
 
 int main()
{
	float arr[10][20]={0};		//holds values of the user's matrix, and its correspodending identity matrix
	int dimensions;		//holds value of dimensions of matrix (square matrix)
	float mainDiag, scalar;		//*mainDiag* is divided from each element in a row i, 
								//so that the element on the main diagonal equals 1
								//*scalar* is multiplied by all elements in a row i ,and then all of the
								//resulting products are subtracted from a row j != row i, with the goal
								//of reducing at least one of the elements to 0
	
	//get dimensions of matrix from user. matrix is square
	cout<<"This program calculates the inverse of up to a 10x10 square matrix"<<endl<<endl;
	cout<<"Please enter the dimensions of the matrix: ";
	cin>>dimensions;
	cout<<endl;
	cout<<"Please enter the elements of the matrix:"<<endl;
	
	//insert all user-entered elements into matrix
	for (int i=0; i<dimensions; i++)
	{
		for (int j=0; j<dimensions; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	//define the elements for the corresponding identity matrix of dimensions x dimensions
	//elements on the main diagonal get 1, all other get 0
	for (int i=0; i<dimensions; i++)
	{
		for (int j=dimensions; j<dimensions*2; j++)
		{
			if (j==dimensions+i)
			{
				arr[i][j]=1;
			}
		}
	}
	
	//begin Gaussian elimination by first multiplying all elements in row i by the element in
	//that rows that lies on the main diagonal.
	for (int i=0; i<dimensions;i++)
	{
		
		//here the value of the element on the main diagonal is stored outside of the loop
		//so that all elements of row i are divided by the same number
		mainDiag=arr[i][i];
		for (int n=0;n<dimensions;n++)
		{
			arr[i][n]/=mainDiag;
			arr[i][n+dimensions]/=mainDiag;
			 
		}
		
		//all elements in row i are then subtracted from their corresponding elements in row j
		//when row j != row i
		for (int j=0;j<dimensions;j++)
		{
			if (j != i)
			{
				//once again, the value of the element i in row j is stored outside of the loop
				//to ensure all elements k in row i are mulitplied by the same number
				scalar=arr[j][i];
				for (int k=0;k<dimensions*2;k++)
				{
						arr[j][k]-=scalar*arr[i][k];
				}
			}
		}
	}
	
	//output the resulting inverse matrix to the screen, I accounted for negatives here for formatting
	cout<<endl;
	cout<<"The inverse matrix is: "<<endl;
	for (int i=0; i<dimensions; i++)
	{
		for (int j=dimensions; j<dimensions*2; j++)
		{
			if (arr[i][j]>=0)
				cout<<" "<<arr[i][j]<<" ";
			else
				cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}