/*File: CS3080lab1.cpp
 *Author: William Hampton
 *Course: CSCI-3080-001
 *Lab Number: 1
 *Purpose: This program gets a user's name, 
 * 	then prints a personalized greeting
 *Due Date:1/23/2018
 */
#include <iostream>
#include <string>

using namespace std;

int main(){
	//create an array, and use it to store the users name.
	//whitespaces welcome.
	char name[30];
	
	cout<<"Please enter your name: ";
	cin.getline(name,30);
	//print personalized greeting
	cout<<"\a";
	cout<<"Hello, "<<name<<"!"<<endl;
	return 0;
}