def main():
    lb=int(input('Enter the lower bound'))
    ub=int(input('Enter the upper bound'))
    for x in range(lb,ub+1):
        val=IsPrime(x)
        if val:
            print(x,' is prime.')

def IsPrime(a):
    for num in range(2,a):
        if a%num==0:
            return False
    return True

main()
    
