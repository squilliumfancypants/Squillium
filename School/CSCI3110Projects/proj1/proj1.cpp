/* Author: William Hampton
 * Course: CSCI 3110-001
 * Project #: 1
 * Filename: proj1.cpp
 * Due: 09/10/2018
*/


#include <iostream>
#include <fstream>
using namespace std;

//Pre- dynamic array of type int with -size- elements, containing integer values read in from a file
//Post- average of the elements in the array, as a double
double calcAvg( const int *dynArray, int size );

//Pre- dynamic array of type int with -size- elements
//Post- a dynamic array of type int with -size * 130%- elements
int * allocateArray( int *dynArray, int &size );

int main( int argc, char * argv[] )
{
    //local variables
    ifstream instream;
    ofstream outstream;
    double average;
    int data, size, count = 0;
    int *dynArr = NULL;

    //connect the input and output streams
    instream.open( "nums.txt" );
    outstream.open( "out.txt" );

    cout << "Enter the number of values as a multiple of 25, between 100 and 250: ";
	
    //get # inputs from user	    
    cin >> size;
    cout << endl;

    if( (size >= 100) && (size <= 250) && (size % 25 == 0) )
    { 
    	//fill the initial array with data from the input file
    	dynArr = allocateArray( dynArr, size );

    	cout << "Allocated " << size << " elements. " << endl;

    	//if files open correctly
    	if( instream.is_open() && outstream.is_open() )
    	{
		//read the file, reallocating the array when user-defined
		//size is exceeded
        	while( instream >> data )
        	{
            		dynArr[count] = data;
	    		count++;

	    		if( count >= size && count < 500 )
            		{	
      				average = calcAvg( dynArr, size );
				cout << "Average so far is " << average << " ";
                		dynArr = allocateArray( dynArr, size );
				cout << "-Array size now is " << size <<endl;
            		}
        	}

		cout << count << " integers were read and the average was " << calcAvg( dynArr, size ) << endl;	
	}
    delete [] dynArr;
    }

    else
    {
	    delete dynArr;
	    cout << "Invalid input."<< endl;
	    exit(1);
    }

    //release the dynamically allocated array back to the system
    dynArr = NULL;

    //close the file streams
    instream.close();
    outstream.close();

    return 0;
}

double calcAvg( const int *dynArray, int size )
{
    double count = 0, sum = 0;

    //calculate the average of the values read at this point
    for( int i = 0; i < size; i++ )
    {
        sum += dynArray[i];
        count++;
    }

    return (sum/count);
}

int * allocateArray( int *dynArray, int &size )
{
    //first allocation
    if( dynArray == NULL )
    {
	    int *temp = new int[size];

	    return temp;
    }

    else
    {
    	//declare and initialize a new dynamic array of the new size
    	double tempSize = size*0.30 +size;

    	//check if max size has been exceeded
    	if( tempSize > 500 )
    	{
		tempSize = 500;
    	}

    	//dynamically allocate a new array of the newly initialized size
    	int *temp = new int[(int)tempSize];

	for( int i = 0; i < size; i++ )
	{
		temp[i] = dynArray[i];
	}
	
	delete [] dynArray;

	dynArray = NULL;

	//reinitialize the size of the array
	size = (int)tempSize;

	return temp;
    }
}

