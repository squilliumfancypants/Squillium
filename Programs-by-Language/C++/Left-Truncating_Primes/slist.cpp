#include "slist.h"
#include <iostream>
using namespace std;


SortedList::SortedList(){
	length = 0;
	currentPos = 0;
}

bool SortedList::IsEmpty() const{
	
	//check if the length is 0
	if(length == 0){
		return true;
	}
	
	else{
		return false;
	}
}

bool SortedList::IsFull() const{
	
	//check if anything is in the list
	if(length == MAX_LENGTH){
		return true;
	}
	
	else{
		return false;
	}
}

int SortedList::Length() const{
	
	return length;
}

void SortedList::Insert(int item, char c){
	
	int index = length - 1;
	
	while(index >= 0 && item < data[index].number){
		data[index + 1].number = data[index].number;
		index--;
	}
	
	data[index + 1].number = item;
	data[index + 1].isPrime = c;
	length++;
	currentPos++;
}

/*void SortedList::Delete(ItemType item){
	
}*/

/*bool SortedList::IsPresent(ItemType item) const{
	//call Reset() before calling this function to reset currentPos to 0
	
}*/

void SortedList::Reset(){
	currentPos = 0;
}

int SortedList::GetNextItem(){
	int item;
	
	item = data[currentPos].number;
	currentPos++;
	
	return item;
}

void SortedList::MarkPrime(char c){
	data[currentPos].isPrime = c;
	
	return;
}

bool SortedList::IsPrime() const{
	if(data[currentPos].isPrime == 'y'){
		return true;
	}
	
	else{
		return false;
	}
}

void SortedList::PrintPrimes() const{
	//call Reset() before calling this function to reset currentPos to 0
	
	for(int i = currentPos; i < length; i++){
		if(data[i].isPrime == 'y'){
			cout<<data[i].number;
		}
	}
	
	cout<<endl;
}

void SortedList::PrintList() const{
	//call Reset() before calling this function to reset currentPos to 0
	
	cout<<"length = "<<length<<endl;
	
	for(int i = currentPos; i < length; i++){
		cout<<data[i].number;
	}
	
	cout<<endl;
}

void SortedList::FillPrimes(int arr[]){
	int index = 0;
	for(int i = currentPos; i < length; i++){
		if(data[i].isPrime == 'y'){
			arr[index] = data[i].number;
			index++;
		}
	}
}
