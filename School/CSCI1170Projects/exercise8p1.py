def main():
    x = int(input("Enter a nonnegative integer: "))
    b = 1
    c=1
    if(x > 0):
        for x in range(1, x+1):
            c=c*b
            b+=1
    else:
        print(x,"is not a nonnegative integer.")
    print(x, "factorial is ",c)
        
main()
        
