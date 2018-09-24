/*
PROGRAMMER:         
William Hampton
Assignment:         
OLA3 , part 1 (24 hour to 12 hour time conversion)  
Class:             
CSCI 2170-005
Course Instructor:  
Dr. Li
Due Date:           
Midnight 3/1/2018
Description:        
This program reads 24 hour time format times from a file, then converts and displays them 
in 12 hour time format
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

//this function takes two parameters, an instream for the file and the file name
//and opens the file for reading
void PrepFile(ifstream& instream);

//this function takes the instream in by reference, and two nonempty parameters of type int by reference, and converts the time
//from 24 hour to 12 hour
void ConvertTime(int& hour[], int& minute[], char& timePeriod[]);

//this function takes in two nonempty parameters of type int by value, and displays the values
//to the screen
void DisplayTime(int hour[], int minute[], char timePeriod[], int& timeCount);

const int TIMES_IN_FILE=50;	//I used this here to make it easier to change the array sizes simultaneously

int main()
{
	//declare variables
	
	ifstream instream;	//used to read in data from file
	int hour[TIMES_IN_FILE], minute[TIMES_IN_FILE];	//used to store the value of converted times for display function
	char timePeriod[TIMES_IN_FILE];	//holds AM and PM info for file times
	string file;	//used to store the file name
	int timeCount=0;	//used to count the number of files
	
	//get the file name from the user
	cout<<"Please enter the file name: ";
	cin>>file;
	
	//call the PrepFile function to open the file for reading
	PrepFile(instream, file);
	
	//call the ConvertTime function to convert the time
	ConvertTime(instream, hour, minute);
	
	//call the DisplayTime function to display the time
	DisplayTime(hour, minute);
	
	
	return 0;
}

void PrepFile(ifstream& instrm, string& fname)
{
	instrm.open("fname");
	assert(instrm)
	return;
}

void ConvertTime(ifstream& instrm, int& hr[], int& min[],char& tP[],int& tcnt)
{
	string line;	//stores the file lines as strings
	string alphaMin,alphaHr="";	//used to intermediate variables for hr and min for use in conversion
	int numMin, numHr;	//used to intermediate variables for hr and min for use in conversion
	int count=0;	//counter
	//read the files in with a while loop, and use a for loop to convert the strings to ints
	while (getline(instrm, line))
	{
		alphaMin="";
		alphaHr="";
		numMin=0;
		numHr=0;
		
		//I read them in backwards, since there is no 0 included for hours under 10 in file
		for (int i=(line.length())-2;i>line.length())-4;i--)
			alphaMin+=line[i];
		for (int i=line.length())-5);i>=0;i--)
			alphaHr+=line[i];
		
		//type cast from strings to ints
		numHr=alphaHr-"0";
		numMin=alphaMin-"0";
		
		//assign AM and PM, convert to 12 hour format and store in arrays
		min[count]=numMin;
		
		if (numHr>11)
		{
			tP[count]='p';
			if (numHr>12)
				hr[i]=numHr-12;
		}
		else
		{
			tP[count]='a';
			hr[i]=numHr;
		}
		tcnt++;
		count++;
	}
	return;
}

void DisplayTime(int hr[], int min[], char tP[],int tcnt)
{
	cout<<"The times, converted to 12 hour format, are:"<<endl<<endl;
	for (i=0;i<tcnt;i++)
		cout<<hr[i]<<":"<<min[i]<<" "<<tP[i]<<endl;
	return;
}