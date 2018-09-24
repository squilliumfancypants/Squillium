/* Author: William Hampton
 * Course: CSCI 3110-001
 * Project #: 2
 * Filename: gaspump.cpp
 * Due: 09/19/2018
*/

#include <gaspump.h>
#include <iostream>

//value constructor
//fuel = fuel type, capacity = tank capacity, price = pricer per gallon
//pre - string, and two doubles
//post - instanciated object of type GasPump
GasPump::GasPump(string fuel, double capacity, double price){
	remainingFuel = pumpCapacity = capacity;
	fuelType = fuel;
	pricePerGallon = price;
	
	fuelDispensed = 0;
	totalFuelDispensed = 0;
	totalRevenues = 0;
	filling = false;
	
}

//dispenses fuel to cars in the driver program, needs to deduct fuel
//the request is in USD
//this function also dispenses remaining fuel if customer request exceeds
//current amount, and turns away the next customer
void GasPump::dispenseFuel(double request){
	
	std::cout << std::fixed;
	std::cout.precision(2);
	
	if(filling || remainingFuel == 0.00)
	{
		replenishFuel();
	}
	
	
	//check remaining fuel
	else if(remainingFuel < (request / pricePerGallon)){
		fuelDispensed = remainingFuel;
		std::cout << " Pumped only $" << (remainingFuel * pricePerGallon)
		<< " of $" << request << " - " << fuelDispensed << " gallons\n";
		
		totalRevenues += (remainingFuel * pricePerGallon);
		totalFuelDispensed += fuelDispensed;
		
		remainingFuel -= fuelDispensed;
		
		filling = true;
	}
	
	//if pump is available
	else{
			fuelDispensed = (request / pricePerGallon);
			std:: cout << " Purchased $" << request << " - " << (request / pricePerGallon) << " gallons\n";
			totalRevenues += request;
			totalFuelDispensed += fuelDispensed;
			remainingFuel -= fuelDispensed;
	}
}
		
//refills tanks remaining fuel to full when it is emptied
void GasPump::replenishFuel(){
	//refill the pump
	remainingFuel = pumpCapacity;
	
	//set status back to available
	filling = false;
	
	std::cout << " Turned away (out of gas)...Tank replenished\n";

}