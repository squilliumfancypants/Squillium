################################################################################
# File: ola4.py
# Author: William Hampton
# Instructor: Dr. Yoo
# Course: CSCII 1170-005
# Date Due: 11/13
# Description:This program calculates student scores, their
#             corresponding grade, and displays these, along
#             with the student the highest score.
# Input: users file
# Output: 1.Purpose of the program,
#           students grades, score,
#           and highest score
################################################################################


# Get user's file

def main():
    print('This program calculates student scores, their')
    print('corresponding grade, and displays these, along')
    print('with the student the highest score.')
    print()
    record_cnt=1
    file=input('Enter a file name: ')
    
# Read the first two line's of user's file.

    try:
        infile=open(file,'r')
    except FileNotFoundError:
        print("Error. There is no file named '",file,"' or '",file,"' is located in a different directory.",sep='')
        file=input("Enter a file name: ")
        infile=open(file,'r')
    print()
    print('User ID \t Score \t Grade')
    print()
    
# Convert the second line into a number, assign a grade

    top_name=infile.readline()
    top_score_string=infile.readline()
    top_score_string.rstrip('\n')
    top_score=float(top_score_string)
    if top_score>=90:
        top_grade='A'
    elif top_score<90 and top_score>=80:
        top_grade='B'
    elif top_score<80 and top_score>=70:
        top_grade='C'
    elif top_score<70 and top_score>=60:
        top_grade='D'
    else:
        top_grade='F'
        
# Print first line, and then use for loops to read the rest of the score.

    print(top_name.rstrip('\n'),'\t',format(top_score,'0.1f'),'\t',top_grade)
    for line in infile:
        record_cnt+=1
        string_score=infile.readline()
        string_score.rstrip('\n')
        
# Break out of loop if EOP is reached

        if string_score=='':
            break
        score=float(string_score)    
        if score>top_score:
            top_score=score
            top_name=line
            
# Assign top score and grades, print

        if score>=90:
            grade='A'
        elif score<90 and score>=80:
            grade='B'
        elif score<80 and score>=70:
            grade='C'
        elif score<70 and score>=60:
            grade='D'
        else:
            grade='F'
        print(line.rstrip('\n'),'\t',format(score,'0.1f'),'\t',grade)
    print()
    print('There are',record_cnt,'records')
    print()
    print(top_name.rstrip('\n'),'has the highest score of',format(top_score,'0.1f'))


main()
    
    
        
