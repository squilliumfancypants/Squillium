##################################################################################################################
# File: OLA4.py
# Author: William Hampton
# Instructor: Dr. Yoo
# Course: CSCI 1170-005
# Date Due: 10/24
# Description: This program takes the user's currency amount, and converts it between different currencies.
# Input: Amount -- amntU2E, amntE2U, etc.
# Output: 1. Purpose of the program.
#         2. Converted amount.
# Formulas: currency conversion rate. eg: Euros = USD*0.84
##################################################################################################################



# Define a void function to print the menu
def print_menu():
    print("This program converts USD to international currencies.")
    print("")
    print("Legend:")
    print("USD = United States Dollars\nEUR = Euros\nCAD = Canadian Dollars\nGBP = Great British Pounds\nCNY = Chinese Yuan")
    print("")
    print("Please choose from the following menu.")
    print("---------------------------------\n---------------------------------")
    print("1: Convert between USD and EUR.\n2: Convert between USD and CAD.\n3: Convert between USD and GBP.\n4: Convert between USD and CNY.\n5: Quit.")
    print("---------------------------------\n---------------------------------")
    print("")

# Define a function to convert user's amount to the desired currency

def currency_converter():
    
    # Input and conversion for EUR
    
    chce2 = int(input("Would you like to convert (1)from or (2)to USD? "))
    while chce2 < 1 or chce2 > 2:
        print(chce2,"is an invalid choice. Please enter either 1 or 2.")
        chce2 = int(input("Would you like to convert (1) from or (2)to USD? "))
    if chce1 is 1:
        if chce2 is(1):
            amntU2E = float(input("Enter the amount in USD: "))
            print("$",amntU2E," is ",format(0.84*amntU2E, ".2f"),"euros .")
            print("")
            main()
        elif chce2 is(2):
            amntE2U = float(input("Enter the amount in euros: "))
            print(amntE2U,"euros is $",format(amntE2U/0.84, ".2f"),".")
            print("")
            main()
     
            
    # Input and conversion for CAD
    
    elif chce1 is 2:
        if chce2 is(1):
            amntU2C = float(input("Enter the amount in USD: "))
            print("$",amntU2C," is ",format(1.25*amntU2C, ".2f"),"CAD .")
            print("")
            main()
        elif chce2 is(2):
            amntC2U = float(input("Enter the amount in CAD: "))
            print(amntC2U,"CAD is $",format(amntC2U/1.25, ".2f"),".")
            print("")
            main()
       
            
    # Input and conversion for GBP
    
    elif chce1 is 3:
        if chce2 is(1):
            amntU2G = float(input("Enter the amount in USD: "))
            print("$",amntU2G," is ",format(0.75*amntU2G, ".2f")," bloody GBP .")
            print("")
            main()
        elif chce2 is(2):
            amntG2U = float(input("Enter the amount in GBP: "))
            print(amntG2U,"bloody GBP is $",format(amntG2U/0.75, ".2f"),".")
            print("")
            main()
            
    # Input and conversion for CNY
    
    elif chce1 is 4:
        if chce2 is(1):
            amntU2Y = float(input("Enter the amount in USD: "))
            print("$",amntU2Y," is ",format(6.59*amntU2Y, ".2f"),"Yuan .")
            print("")
            main()
            
        elif chce2 is(2):
            amntY2U = float(input("Enter the amount in CNY: "))
            print(amntY2U,"Yuan is $",format(amntY2U/6.59, ".2f"),".")
            print("")
            main()
        

# Define a main function, which calls the converter and menu functions.

def main():
    
    print_menu()
    
    # Set variable "chce1" as global, so that the user's input for "chce1" can be used in the currency converter function
    
    global chce1
    chce1 = int(input("Enter your choice: "))
    
    # This loop controls when the program stops
    
    while(chce1 != 5):
        if chce1 is 1 or chce1 is 2 or chce1 is 3 or chce1 is 4:
            currency_converter()
        else:
            print(chce1,"is an invalid choice.")
            print("Please Choose from the menu.")
            print("")
            main()
main()
                
                
        
    


    
    
        
