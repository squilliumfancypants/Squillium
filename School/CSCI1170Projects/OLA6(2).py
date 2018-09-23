#######################################################################################
# Author: William Hampton                                                           
# Professor: Dr. Yoo
# Program name: OLA6.py
# Date: 11/23/2017
# Class: CSCI 1170-005
# Purpose:  This program gets a file containing names and answers, and
#           grades the answers.Also calculates the class average.
# Program Input: the user inputs an exisiting file, if file does not exist, exception
#                is handled
# Program Output: program prints the key, IDs, answers, numerical score,
#                 standing based on average, class average, and top student along
#                 their score
# Formulas: 1. average= the sum of the classes grades, divided by the total number
#              of students (total/stuCount)
#           2. grade= the students score divided by the number of questions
#######################################################################################


#1-define the main function

def main():
    file=input('Enter a file: ')
    #1.1-the try/except suite below prints a custom error message if file is not found
    try:
        infile=open(file,'r')
    except FileNotFoundError:
        print('The file',file,'does not exist. Please enter another file.')
        #1.2-return user back to main function if the file doesn't exist
        main()
        return
    #1.3-read the first line into the variable 'key'
    key=infile.readline()
    #1.4-prime the variable stuCount
    #1.5-create lists for student scores, IDs, and answers
    stuCount=0
    score_list=[]
    ID_list=[]
    Answers_list=[]
    #1.6-read each line, removing white space and end of line characters
    for line in infile:
        line.strip()
        #1.7-increment stuCount 1 for each record
        stuCount+=1
        #1.7.1-slice the begining of the line into a string containing the record's ID
        ID=line[0:9]
        #1.7.2-append the string ID to the list ID_list
        ID_list.append(ID.strip())
        #1.7.3-slice and append the end of the line to the list Answers_list
        Answers=line[9:-1]
        Answers_list.append(Answers)
        #1.7.4-call the GradeMC function with the arguments 'Answers' and 'key'
        score=GradeMC(Answers, key)
        score_list.append(score)
    #1.8-close the file
    infile.close()
    #1.8.1-call the ClassAv function, to get the class average
    average=ClassAv(score_list,stuCount)
    #1.8.2-call the StudentStanding funtion, to get a list of the students standings
    standing_list=StudentStanding(score_list, average)
    #1.8.3-call the BestStudent function, to determine the student with the best score, and their score
    topStudent=BestStudent(ID_list,score_list)
    #1.8.4-print the key
    print('Key: ',key.strip(),'\t There are',len(key)-1,'problems')
    print()
    #1.8.5-print a heading for the calculated outputs
    print('ID \t\t Answers \t\t Score \t Standing')
    print()
    #1.8.6-print the outputs of each function, 1 record at a time
    for x in range(stuCount):
        print(ID_list[x],'\t',Answers_list[x],'\t',score_list[x],'\t',standing_list[x])
    print()
    #1.8.7-print the class average, formatted to 1 decimal place
    print('The average class average was',format(average,'.1f'))
    #1.8.8-print the number of records in the file
    print('There are',stuCount,'records in the file')
    #1.8.9-print the student ID with the highest score, and their score
    print('The student with the highest score was: ',topStudent[0],'with a score of',topStudent[1])
    
#3-define the ClassAv function
#3.1-ClassAv purpose: this function accepts two arguments, and returns the Classes average score
#3.1.2-ClassAv parameters: the parameter here is the variable average. it is calculated by dividing
#                        the variable element refrenced by the index of score_list, score_list[i]
#                        into the sum of the indiviual scores
#3.1.3-ClassAv pre-condition: one non-empty list, score_list, and a non-empty integer variable, stuCount
#3.1.4-GradeMC post-condition: returns the variable average

def ClassAv(score_list,stuCount):
    #3.2.1-prime the variable 'total'
    total=0
    #3.2.3-use a for loop to add the scores from score_list
    for i in range(len(score_list)):
        total+=score_list[i]
    #3.2.4-calculate and return average to the calling function
    average=total/stuCount
    return average

#2-define the GradeMC function
#2.1-GradeMC purpose: this function accepts two arguments, and returns the score associated with the ID
#2.1.2-GradeMC parameters: the parameter here is the variable score. It is increased if the argument
#    Answers matches the argument key
#2.1.3-GradeMC pre-condition: two non-empty variables, Answers and key
#2.1.4-GradeMC post-condition: returns the variable score

def GradeMC(Answers,key):
    #2.2.1-prime the variable 'score' to 0
    score=0
    #2.2.2-use a for loop to calculate score. if indexed Answers match indexed key, add 1 to score
    for i in range(len(key)-1):
        if Answers[i]==key[i]:
            score+=1
    #2.2.3-return score to the calling function
    return score

#4-define the StudentStanding function
#4.1-StudentStanding purpose: this function accepts two arguments, and returns the students standing
#                             compared to the class average
#4.1.2-StudentStanding parameters: the parameter here is the variable standing. standing is
#                                is checked against several predefined intervals in order to
#                                determine whether the student is above or below average
#4.1.3-StudentStanding pre-condition: one non-empty list, score_list, and a non-empty variable,average
#4.1.4-StudentStanding post-condition: returns the variable standing

def StudentStanding(score_list, average):
    #4.2.1-create a list called standing_list
    standing_list=[]
    #4.2.2-used a loop to find standing and append to list
    for i in range(len(score_list)):
        if score_list[i]>average:
            standing='above average'
            standing_list.append(standing)
        elif score_list[i]<average:
            standing='below average'
            standing_list.append(standing)
        else:
            standing='average'
            standing_list.append(standing)
    #4.2.3-return standing_list to the calling function
    return standing_list

#5-define the BestStudent function
#5.1.1-BestStudent purpose: this function accepts two arguments, and returns the highest ID score, as well as
#                         the associated ID
#5.1.2-BestStudent parameters: the parameter here are the variables topStudent and topScore, and the
#                            list topStudent_list
#5.1.3-BestStudent pre-condition: two non-empty list, ID_list, which contains strings, and score_list,
#                               which contains integer values
#5.1.4-BestStudent post-condition: returns the list topStudent_list

def BestStudent(ID_list,score_list):
    #5.2.1-create two variables, topStudent and topScore. prime them as the first ID and score from the file
    topStudent=ID_list[0]
    topScore=score_list[0]
    #5.2.2-use a for loop to find the topStudent and the topScore
    for i in range(len(ID_list)):
        currentscore=score_list[i]
        if score_list[i]>topScore:
            topScore=currentscore
            topStudent=ID_list[i]
    #5.2.3-create a list called topStudent_list
    topStudent_list=[]
    #5.2.4-append topStudent and topScore to the topStudent_list
    topStudent_list.append(topStudent)
    topStudent_list.append(topScore)
    #5.2.5-return the topStudent_list to the calling function
    return topStudent_list

#6-call the main function

main()
        
            
