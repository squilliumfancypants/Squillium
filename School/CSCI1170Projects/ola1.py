#FILE: ola1.py
#AUTHOR: William Hampton
#Instructor: Dr. Yoo
#COURSE:  CSCI 1170-005
#Date Due: 9/11/2017
#DESCRIPTION: This program determines the average of three test scores.
#INPUT: Three test score -- test1(float), test2(float), and test3(float)
#OUTPUT: 1. Purpose of the program.
#        2. The average of the three scores -- average (float) with
#		an identifying message.
#Formulas:  average = (test1 + test2 + test3)/3
############################################################################

def main():
	#1. Display the purpose of the program
	print("This program computes the average of three scores")
	#2. Read in the three test scores
	#2.1 Get the first score from the user.
	test1 = int( input("Enter the first test score:  "))
	print("You Entered  ", test1)
	#2.2 Get the second score from the user.
	test2 = int( input("Enter the second test score:  "))
	print("You Entered  ", test2)
	#2.3 Get the third score from the user.
	test3 = int( input("Enter the third test score:  "))
	print("You entered  ", test3)
	#3. Calculate the average of the test scores
	average = (test1 + test2 + test3)/3
	#4. Print the average with an identifying messgage.
	print("The average of the three scores is:  ", average)
	print("")

#Call the main function.
    
