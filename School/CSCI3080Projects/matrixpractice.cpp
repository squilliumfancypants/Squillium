#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int arr1D[2], arr2D[2];
	int arr1[8][8],arr2[8][8];
	cout<<"Enter the dimensions of matrix 1: "<<endl;
	
	for(int i=0;i=<1;i++){
		cin>>arr1D[i];
	}
	/*
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			//the loop gets each number from the user and prints
			cin>>arr1[i][j];
		cout<<endl;
		 }
	}*/
	cout<<arr1D[0]<<arr1D[1]<<endl;
	return 0;
}