/* Author: William Hampton
 * Course: CSCI 3110-001
 * Project #: 2
 * Filename: gaspump.h
 * Due: 09/19/2018
*/

#ifndef GASPUMP_H
#define GASPUMP_H

#include <string>
using namespace std;

class GasPump{
	
public:
		//fuel = fuel type, capacity = tank capacity, price = pricer per gallon
		//pre - string, and two doubles
		//post - instanciated object of type GasPump
		GasPump(string fuel, double capacity, double price);
		
		//--------------------------accessor functions ------------------------------
		
		//inline function that returns fuel type as a string
		string getFuelType() const{ return fuelType; }
		
		//inline function that returns total fuel dispensed as a double
		double getTotalFuelDispensed() const{ return totalFuelDispensed; }
		
		//inline function that returns total revenues collected as a double
		double getTotalRevenues() const{ return totalRevenues; }
		
		//dispenses fuel to cars in the driver program, needs to deduct fuel
		//this function also dispenses remaining fuel if customer request exceeds
		//current amount, and turns away the next customer
		void dispenseFuel(double request);
		
		
		
		
		
private:

		string fuelType;
		double remainingFuel;		//in gallons
		double pumpCapacity;		//in gallons
		double pricePerGallon;		//in USD
		double fuelDispensed;	//holds value of a single amount of disepensed fuel
		double totalFuelDispensed;
		double totalRevenues;
		bool filling;
		
		//refills tanks remaining fuel to full when it is emptied
		void replenishFuel();
	
};

#endif
