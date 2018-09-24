/* Author- William Hampton
 * Date- 4/21/2018
 * Purpose- this is the main file for a program that takes in data from
 * 			 a file and creates an unsorted linked list with the data
*/


#include "list.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
	List lList;
	//ifstream instream;
	ItemType item=0;
	ItemType search;
	ItemType delItem;
	
	//instream.open("data.dat");		//connect the stream to the file containing the book titles
	
	//assert(instream);		//check for successful open
	
	while (item<10)
	{
		lList.Insert(item);
		item++;
	}
	
	lList.Reset();
	
	cout<<"These are the items currently in the list: "<<endl;
	while (lList.HasNext())
	{
		cout<<lList.GetNextItem()<<endl;
	}
	
	lList.Reset();
	
	cout<<"Please enter an item to search for: ";
	cin>>search;
	
	if (lList.IsThere(search))
		cout<<search<<" is in the list."<<endl;
	else
		cout<<search<<" is not in the list."<<endl;
	
	cout<<"The current length of the list is "<<lList.GetLength()<<endl;
	
	cout<<"Making a copy of the list."<<endl;
	List copyList(lList);
	
	copyList.Reset();
	cout<<"These are the items currently in the copied list: "<<endl;
	
	while (copyList.HasNext())
	{
		cout<<copyList.GetNextItem()<<endl;
	}
	
	cout<<"Enter a item to delete: "<<endl;
	cin>>delItem;
	
	lList.Delete(delItem);
	
	cout<<"These are the items currently in the list: "<<endl;
	while (lList.HasNext())
	{
		cout<<lList.GetNextItem()<<endl;
	}
	
	return 0;
}