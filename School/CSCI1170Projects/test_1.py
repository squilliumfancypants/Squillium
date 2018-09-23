def main():
    file=input('Enter a file: ')
    infile=open(file,'r')
    table=[]
    for line in infile:
        row=line.split()
        intRw=[]
        for ele in row:
            intRw.append(int(ele))
        table.append(intRw)
    print(file,'converted to a 2D list: ')
    for i in table:
        print(i)
    print()
    value=1
    while value!=0:
        r=0
        c=0
        count=0
        value=int(input('Enter an integer, or enter 0 to exit. '))
        if value==0:
            break
        for i in table:
            for c in range(len(i)):
                if value<table[r][c]:
                    count+=1
            r+=1
        print('There are',count,'numbers greater than',value)
        print()
main()
