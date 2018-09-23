/* Author: William Hampton
 * Course: CSCI 3110-001
 * Project #: 2
 * Filename: proj2.cpp
 * Due: 09/19/2018
*/

#include <iostream>
#include <gaspump.h>

int main(int argc, char **argv)
{
	//this is the driver program for the project
	//it uses rng to decide what amount of gas a customer wants
	//instanciatiates 3 instances of gas pumps (unleaded, midgrade, premium)
	
	int rnd;
	int amount;
	srand(1000);
	GasPump* fuelPump;
	
	GasPump unleadedPump("Unleaded", 200, 2.82);
	GasPump midgradePump("Midgrade", 125, 2.97);
	GasPump premiumPump("Premium+", 100, 3.25);
	
	
	for(int i = 1; i < 51; i++){
		fuelPump = &unleadedPump;
		rnd = rand()%7;
		
		if(rnd == 4 || rnd == 5){
			fuelPump = &midgradePump;
		}
		
		else if(rnd == 6){
			fuelPump = &premiumPump;
		}
		
		std::cout << "Vehicle " << i << " " << fuelPump->getFuelType();
		
		amount = ( (rand() % 6) + 6 ) * 5;
		
		fuelPump->dispenseFuel( (double)amount );
	}
	
	fuelPump = &unleadedPump;
	std::cout << "Pump " << fuelPump->getFuelType() << " dispensed " << fuelPump->getTotalFuelDispensed()
	<< " and collected $" << fuelPump->getTotalRevenues() << "\n";
	
	fuelPump = &midgradePump;
	std::cout << "Pump " << fuelPump->getFuelType() << " dispensed " << fuelPump->getTotalFuelDispensed()
	<< " and collected $" << fuelPump->getTotalRevenues() << "\n";
	
	fuelPump = &premiumPump;
	std::cout << "Pump " << fuelPump->getFuelType() << " dispensed " << fuelPump->getTotalFuelDispensed()
	<< " and collected $" << fuelPump->getTotalRevenues() << "\n";
	
	
	return 0;
}
