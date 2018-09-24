 /*
 *PROGRAMMER:         
 *William Hampton
 *Assignment:         
 *CLA17 
 *Class:             
 *CSCI 2170-005
 *Course Instructor:  
 *Dr. Li
 *Due Date:           
 *Midnight 4/20/2018
 *Description:        
 *This is the main file for a program that reads book info from a file,
 * and creates a sorted array-based list with that info
 */

#include "slist.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream instream;			//stream used for reading the file
	SortedList sList;		//array of structs used to store the book info from the file
	BookType book;
	string author;
	int count=0;
	
	instream.open("books.dat");			//connect the stream to the file
	
	assert(instream);		//check for successful open
	
	//read the books in and store them in the array of structs
	while (!sList.IsFull() && !instream.eof())
	{
		getline(instream, name);
		cout<<name<<endl;
		getline(instream, auth);
		cout<<auth<<endl;
		instream>>year;
		cout<<year<<endl;
		instream.ignore(100, '\n');
		/*
		book.title="title";
		book.author="author";
		book.publicationYear=count;
		cout<<book.publicationYear<<endl;
		 */
		sList.Insert(book);
		count++;
		cout<<"Made it through the loop "<<count<<" times"<<endl;
	}
	
	instream.close();
	
	sList.Reset();
	
	cout<<"This is the current list: "<<endl;
	
	sList.PrintList();
	
	cout<<"Enter the name of an author: "<<endl;
	getline(cin, author);
	
	return 0;
}
