/*File: CS3080OLA6.cpp
 *Author: William Hampton
 *Course: CSCI-3080-001
 *Lab Number: 6
 *Purpose: This program emulates a finite state machine recognizer. It uses a table lookup to
 *			change state and produce output based on input which has been redirected from a file
 *Due Date:4/30/2018
 */

#include <iostream>
using namespace std;

int main()
{
	char input;		//used to store the input
	int output=0;		//used to store the output
	int table[10][8]={0};
	int state=0;
	
	//below I initialize the matrix to represent a state table. the current states are purely for illustration of concept
	//row 6 is the recognizing state. the state '9' represents reading the newline character
	//current state	//input in ASCII //next state	 //input in ASCII  //next state    //input in ASCII  //next state    //output
	table[0][0]=0;  table[0][1]=10;  table[0][2]=9;  table[0][3]=97;   table[0][4]=1;  table[0][5]=98;   table[0][6]=7;  table[0][7]=0;
	table[1][0]=1;  table[1][1]=10;  table[1][2]=9;  table[1][2]=97;   table[1][4]=2;  table[1][5]=98;   table[1][6]=3;  table[1][7]=0;
	table[2][0]=2;  table[2][1]=10;  table[2][2]=9;  table[2][3]=97;   table[2][4]=1;  table[2][5]=98;   table[2][6]=4;  table[2][7]=0;
	table[3][0]=3;  table[3][1]=10;  table[3][2]=9;  table[3][3]=97;   table[3][4]=5;  table[3][5]=98;   table[3][6]=4;  table[3][7]=1;
	table[4][0]=4;  table[4][1]=10;  table[4][2]=9;  table[4][3]=97;   table[4][4]=5;  table[4][5]=98;   table[4][6]=3;  table[4][7]=1;
	table[5][0]=5;  table[5][1]=10;  table[5][2]=9;  table[5][3]=97;   table[5][4]=7;  table[5][5]=98;   table[5][6]=6;  table[5][7]=0;
	table[6][0]=6;  table[6][1]=10;  table[6][2]=9;  table[6][3]=97;   table[6][4]=7;  table[6][5]=98;   table[6][6]=7;  table[6][7]=1;
	table[7][0]=7;  table[7][1]=10;  table[7][2]=9;  table[7][3]=97;   table[7][4]=8;  table[7][5]=98;   table[7][6]=8;  table[7][7]=0;
	table[8][0]=8;  table[8][1]=10;  table[8][2]=9;  table[8][3]=97;   table[8][4]=7;  table[8][5]=98;   table[8][6]=7;  table[8][7]=0;
	
	//this machine (emulated here by the while loop) is designed to recieve redirected file input
	while (1)
	{
		//I excluded and end of line
		cout<<table[state][7];
		cin.get(input);		//get the input
		if(input=='\n')		//the machine stops upon reading a newline character
			break;
		
		//check the row corresponding with the current state for a matching input
		for (int cell=1; cell<7; cell++)
		{
			if(table[state][cell]==(int)input)		//change state accordingly
				state=table[state][cell+1];
		}
	}
	
	return 0;
}
