/*File: CS3080OLA3.cpp
 *Author: William Hampton
 *Course: CSCI-3080-001
 *Lab Number: 3
 *Purpose: This program gets a nxn matrix from the user, and performs Gaussian elimination
 * 			to find the identity matrix of the user's matrix.
 *Due Date:2/6/2018
 */
 #include <iostream>
 using namespace std;
 
 int main()
{
	//initialize variables and arrays
	float arr[10][20]={0};
	int dimensions;
	float number;
	float scalar;
	
	cout<<"Enter the dimensions of the matrix: "<<endl;
	cin>>dimensions;
	
	for (int i=0; i<dimensions; i++)
	{
		for (int j=0; j<dimensions; j++)
		{
			cin>>arr[i][j];
		}
	}
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
	for (int i=0; i<dimensions;i++)
	{
		for (int n=0;n<dimensions;n++)
		{
			if (n != i)
			arr[i][n]/=arr[i][i];
			arr[i][n+dimensions]/=arr[i][i];
		}
		arr[i][i]/=arr[i][i];
		for (int j=0;j<dimensions;j++)
		{
			if (j != i)
			{
				scalar=arr[j][i];
				for (int k=0;k<dimensions*2;k++)
				{
						arr[j][k]-=scalar*arr[i][k];
				}
			}
		}
	}
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