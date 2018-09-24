//This program builds left-truncatable prime numbers
//At the end, the program will truncate one digit at a time, and every remaining number will
//be prime
#include "slist.h"

#include <iostream>
using namespace std;

int SIZE = 10;

void CreateLTPrime(int array[], int aSize, SortedList list);

void PrintArray(int array[], int &aSize);

void Truncate(int array[], int &aSize);

int main(int argc, char **argv)
{
	SortedList list;
	int listSize = 52;
	int primes[SIZE];
	int array[SIZE];
	int aSize = SIZE;
	
	bool prime;
	list.Insert(1, 'n');
	list.Insert(2, 'y');
	list.Insert(3, 'y');
	list.Insert(4, 'n');
	
	
	for(int i = 5; i < listSize; i++){
		prime = true;
		for(int j = 2; j < i/2; j++){
			if(i % j == 0){
				prime = false;
			}
		}
		if(prime){
			list.Insert(i, 'y');
		}
		
		else{
			list.Insert(i, 'n');
		}
	}
	
	//print out the primes in the list, and the list itself for reference
	list.Reset();
	
	list.PrintPrimes();
	
	list.Reset();
	
	list.PrintList();
	
	list.Reset();
	
	list.FillPrimes(primes);
	
	while(aSize >= 0){
		PrintArray(primes, aSize);
		Truncate(primes, aSize);
	}
	
	return 0;
}

void CreateLTPrime(int array[], int aSize, SortedList list){
	
	int temp = aSize;
	
	while(temp >= 0){
		if(list.IsPrime()){
			array[temp] = list.GetNextItem();
			temp--;
		}
	}
}

void PrintArray(int array[], int &aSize){
	//prints out the array of primes
	for(int i = 0; i < aSize; i++){
		cout<<array[i];
	}
	
	cout<<endl;
}

void Truncate(int array[], int &aSize){
	for(int i = 0; i <= aSize; i++){
		array[i] = array[i + 1];
	}
	
	aSize--;
}

