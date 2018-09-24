def Func1(n):
    for i in range(2):
        n.append(i)
    return n

def main():
    array=[]
    arr2=[]
    #for i in range (3):
    #    array.append(i)
    #    print(array[i])
    #print("")
    arr2=Func1(array)
    for i in range(len(arr2)-1):
        for j in range(len(arr2)-1):
                   print(arr2[i][j])
                   print("")
    
    
main()

