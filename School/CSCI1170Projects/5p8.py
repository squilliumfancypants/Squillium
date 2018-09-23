#File Name: 5p8.py
#Author: William Hampton
#Section: 1170-005

#This program creates a recipe base on the number cookies the user needs.




def main():


    sugar= 1.5/48
    butter= 1/48
    flour= 2.75/48
    cookies = int(input("How many cookies do you want to make? "))

 

    print("You need ", cookies*sugar, "cups of sugar")
    print("You need ", cookies*butter,"cups of butter")
    print("You need ", cookies*flour,"cups of flour")
                  

main()
