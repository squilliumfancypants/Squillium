//main (client) file for imaginaryClass project

#include "imaginaryClass.h"
#include <iostream>
using namespace std;

/*void Assign(MyComplexClass aC[5]);*/

void Add(MyComplexClass c1, MyComplexClass c2);

int main()
{
	MyComplexClass c1, c4;
	float real, imaginary;
	//MyComplexClass aC[5];
	
	
	c1.SetValues(5.5, 3);
	
	cout<<"Enter the real component of the complex number: ";
	cin>>real;
	
	cout<<"Enter the imaginary component of the complex number: ";
	cin>>imaginary;
	
	MyComplexClass c2(real, imaginary);
	
/*	Assign(aC);*/
	
	MyComplexClass c3(const MyComplexClass& c2);
	
	/*for (int i=0; i<5; i++)
	{
		aC[i].Display();
		cout<<endl;
	}*/
	
	Add(c1, c2);
	
	return 0;
}

void Add(MyComplexClass c1, MyComplexClass c2)
{

	c1.Display();
	cout<<" + ";
	c2.Display();
	cout<<" = ";
	c1+c2;
	c1.Display();
	
	
	return;
}

/*void Assign(MyComplexClass aC[5])
{
	float r, imag;
	
	cout<<"Enter the values into the array, in the form a+bi: "<<endl;
	for (int i=0; i<5; i++)
	{
		cin>>r;
		cin.ignore(100,'+');
		cin>>imag;
		cin.ignore(100,'i');
		cin.ignore(100,'\n');
		aC[i].SetValues(r, imag);
	}
}*/
