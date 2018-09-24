def main():
    lb=int(input("Enter the lower bound"))
    ub=int(input("Enter the upper bound"))
    for i in range(lb,ub+1):
        num=isPrime(i)
        if num:
            print(i," is prime")
        
def isPrime(a):
    val=True
    for n in range(2,a,1):
        if a%n==0:
            val=False
            return val
    return val

main()
    
