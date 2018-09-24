############################## OLA 3 ###########################################
# Program name: OLA3
# Date: 10/9/2017
# Class: CSCI 1170-005
# Purpose: This program calculates the shipping cost for the user.
################################################################################

def main():
    
    #define shipping classes, and get user input weight
    
    toyweight = (float(input("Enter your toy's weight in lbs: "))+0.5)
    format(toyweight, "0.2")
    if toyweight < 1:
        s = 4.49
        e = 6.49
        
    else:     
        s = (4.49+(50/100)*(int(toyweight)))
        e = (((int(toyweight))*(99/100))+6.49)
        
    #define parameters for one day shipping calculations
    
    if(float(toyweight) > 0 and float(toyweight)-0.5 > 0 and float(toyweight)-0.5 <=1):
        
        #this statement defines eligibility for one day shipping.
        
        if(float(toyweight)-0.5 <= 1):
            selection1 = str(input("Your toy is eligible for one day shipping. Would you like to select one day shipping? Type Y/N. "))
            if selection1== "Y" or selection1=="y" or selection1=="yes" or selection1=="YES" or selection1=="Yes":
                print("Your shipping cost is $19.99. Your package will arrive within one day.")
            
            elif selection1=="No" or selection1=="no" or selection1=="n" or selection1=="N" or selection1=="nO":
                selection2 = str(input("Select one of the following shipping rates: standard, or expedited. Type s for standard shipping, or e for expedited shipping. "))

                if selection2=="s" or selection2=="S":
                    print("Your shipping cost is $", format(s, "0.2f"), ". Your Package will arrive in 4 to 10 business days.")
                    
                elif selection2=="e" or selection2=="E":
                    print("Your shipping cost is $", format(e, "0.2f"), ". Your Package will arrive in 2 to 6 business days.")
                    
                else:
                    print("INVALID CODE:", selection2,"Terminating")
                    exit
            else:
                print("INVALID CODE. Terminating.")
     
    #define parameters for expedited and standard shipping calculations
                
    elif(toyweight-0.5 >= 1):
        selection3 = str(input("Select from the following rates: standard, or expedited. Type s for standard, or e for expedited. "))
        if selection3=="s" or selection3=="S":
            print("Your shipping cost is $", format(s, "0.2f"), ". Your Package will arrive in 4 to 10 business days.")
        elif selection3=="e" or selection3=="E":
            print("Your shipping cost is $", format(e, "0.2f"), ". Your Package will arrive in 2 to 6 business days.")
        else:
            print("INVALID CODE:",selection3, " Terminating.")
            exit
            
    #this statement alerts the user that they have entered an invalid value for their toy weight
            
    else:
        print("Your toy's weight must be greater than 0 lbs. Terminating.")
        exit
main()    
                  
