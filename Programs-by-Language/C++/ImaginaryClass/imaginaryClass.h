//header file for imaginaryClass project

#ifndef IMAGINARYCLASS_H
#define IMAGINARYCLASS_H

typedef float ImaginaryType;

class MyComplexClass
{
	
public:
	
	MyComplexClass();
	//default constructor
	
	MyComplexClass(const MyComplexClass& otherObject);
	//copy constructor
	
	MyComplexClass(float r, ImaginaryType i);
	//value consructor
	
	void SetValues(float real, ImaginaryType);
	//sets the values of an existing complex number
	
	float GetReal();
	//displays the value of the real component of a complex number
	
	void Display();
	//displays the values of an existing complex number
	
	bool EqualTo(const MyComplexClass& otherObject);
	
	bool operator ==(const MyComplexClass& rhs) const;
	
	void operator +(const MyComplexClass& rhs);
	
	
private:
	
	float real;
	
	ImaginaryType imaginary;
	
	
};

#endif