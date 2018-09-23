# Author: William Hampton
# Exercise: 6 - Logical Expressions

def main():

    males = int(input("Enter the number of males: "))
    print("")
    females = int(input("Enter the numer of females: "))
    total = males+females
    percentmales = males/total
    percentfemales = females/total
    print("")
    print("Percent males: "+format(percentmales, '.0%'))
    print("Percent females: "+format(percentfemales, '.0%'))
    
main()
                
