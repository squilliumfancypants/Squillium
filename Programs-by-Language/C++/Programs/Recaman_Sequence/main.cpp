#include <stdio.h>
#include "linkedlist.h"
using namespace std;



int main(int argc, char **argv)
{
	int MAXLENGTH = 450;
	
	List a;
	
	for(ItemType i = 0; i < MAXLENGTH; i++){
		a.Insert(i);
	}
	
	a.Reset();
	
	cout<<a.GetLength()<<" items in the list"<<endl<<endl;
	
	ItemType temp;
		
	for(int i = 0; i < MAXLENGTH; i++){
		int k = i;
		temp = a.GetCurrentItem();
		
		while(k != 0 && a.HasPrevious()){
			a.GetPreviousItem();
			k--;
		}
		
		if(a.GetMark() == 'n'){
			cout<<a.GetCurrentItem()<<endl;
			a.MarkNode();
		}
		
		else{
			while(a.GetCurrentItem() !=temp){
				a.GetNextItem();
			}
			
			while(a.GetCurrentItem() != temp + i){
				a.GetNextItem();
			}
			
			if(a.GetMark() == 'n'){
				cout<<a.GetCurrentItem()<<endl;
				a.MarkNode();
			}
		}
		
		cout<<"i: "<<i<<endl;
	}
	
	a.~List();
	
	return 0;
}
