def main():
    file=input('Enter a file name: ')
    inFile=open(file,'r')
    Lname=[]
    Lscore=[]
    for line in inFile:
        line=line.strip()
        Lname.append(line[0:5])
        Lscore.append(line[5:])
    print(Lname,Lscore)
main()

        
