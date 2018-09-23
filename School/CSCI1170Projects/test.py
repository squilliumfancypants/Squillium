def main():
    file=input('Enter a file: ')
    try:
        infile=open(file,'r')
    except FileNotFoundError:
        print('The file',file,'does not exist. Please enter another file.')
        main()
        return
    key=infile.readline()
    stuCount=0
    score_list=[]
    grade_list=[]
    ID_list=[]
    Answers_list=[]
    for line in infile:
        line.strip()
        stuCount+=1
        ID=line[0:9]
        ID_list.append(ID.strip())
        Answers=line[9:-1]
        Answers_list.append(Answers)
        score=GradeMC(Answers, key)
        score_list.append(score)
        grade=GradeScore(score)
        grade_list.append(grade)
    infile.close()
    average=ClassAv(score_list,stuCount)
    standing=StudentStanding(score_list, average)
    standing_list=[]+standing
    topStudent=BestStudent(ID_list,score_list)
    print('Key: ',key.strip(),'\t There are',len(key)-1,'problems')
    print()
    print('ID \t\t Answers \t\t Score \t\t Grade \t Standing')
    print()
    for x in range(stuCount):
        print(ID_list[x],'\t',Answers_list[x],'\t',score_list[x],'\t',grade_list[x],'\t',standing_list[x])
    print()
    print('The average class average was',format(average,'.1f'))
    print('There are',stuCount,'records in the file.')
    print('The student with the highest score was: ',topStudent[0],'with a score of',topStudent[1])

def ClassAv(score_list,stuCount):
    total=0
    for i in range(len(score_list)):
        total+=score_list[i]
    average=total/stuCount
    return average

def GradeMC(Answers,key):
    score=0
    for i in range(len(key)-1):
        if Answers[i]==key[i]:
            score+=1
    return score

def GradeScore(score):
    grade=(score/20)*100
    if grade>=90:
        alGrade='A'
    elif grade<90 and grade>=80:
        alGrade='B'
    elif grade<80 and grade>=70:
        alGrade='C'
    elif grade<70 and grade>=60:
        alGrade='D'
    else:
        alGrade='F'
    return alGrade

def StudentStanding(score_list, average):
    standing_list=[]
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
    return standing_list

def BestStudent(ID_list,score_list):
    topStudent=ID_list[0]
    topScore=score_list[0]
    for i in range(len(ID_list)):
        currentscore=score_list[i]
        if score_list[i]>topScore:
            topScore=currentscore
            topStudent=ID_list[i]
    topStudent_list=[]
    topStudent_list.append(topStudent)
    topStudent_list.append(topScore)
    return topStudent_list

main()
        
            
