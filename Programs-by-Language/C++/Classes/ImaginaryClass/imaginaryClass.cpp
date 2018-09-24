//implementation file for imaginaryClass project


#include "imaginaryClass.h"
#include <iostream>
using namespace std;


MyComplexClass::MyComplexClass()
//default constructor
{
	real=0.0;
	imaginary=0.0;
}

MyComplexClass::MyComplexClass(const MyComplexClass& otherObject)
//copy constructor
{
	MyComplexClass object;
	real=otherObject.real;
	imaginary=otherObject.imaginary;
}

MyComplexClass::MyComplexClass(float r, ImaginaryType i)
//value consructor
{
	real=r;
	imaginary=i;
}

void MyComplexClass::SetValues(float r, ImaginaryType i)
//sets the values of an existing complex number
{
	real=r;
	imaginary=i;
}

float MyComplexClass::GetReal()
//displays the value of the real component of a complex number
{
	return real;
}

void MyComplexClass::Display()
//displays the values of an existing complex number
{
	cout<<real<<" + "<<imaginary<<"i"<<endl;
}

bool MyComplexClass::EqualTo(const MyComplexClass& otherObject)
{
	if (real==otherObject.real && imaginary==otherObject.imaginary)
		return true;
		
	else return false;
}

bool MyComplexClass::operator ==(const MyComplexClass& rhs) const
{
	return (real==rhs.real && imaginary==rhs.imaginary);
}
	
void MyComplexClass::operator +(const MyComplexClass& rhs)
{
	real=real+rhs.real;
	imaginary=imaginary+rhs.imaginary;
	
	return;
}

