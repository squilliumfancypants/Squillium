############################# OLA 2 ###########################################
# File: ola2.py
# Author: William Hampton
# Instructor: Dr. Yoo
# Class: CSCI 1170 - 005
# Date: 09/17/2017
# Purpose: This program converts the users temperatures, first from Farenheit to
# Celsius, and then from Celsius to Farenheit.
###############################################################################

def main():
    # Dispay the name of the program, and skip line.
    print("Welcome to the Temperature Converter")
    print("")

    # Get the users temperature, in Farenheit. 
    tempF = float(input("Enter the temperature in Farenheit: "))
    # Convert the users temperature to Celsius, and display the result, rounded
    # to two decimal places. Skip a line.
    print("In Celsius that would be ", format((tempF-32)*(5/9),'.2f'),"degrees");
    print("")

    # Get the users temperature, in Celsius.
    tempC = float(input("Enter the temperature in Celsius: "))
    # Convert the users temperature to Farenheit, and display the result, rounded
    # to two decimal places.
    print("In Farenheit that would be ", format((32+(9/5)*tempC),'.2f'),"degrees")

main()
          


                  
                
                  
    
