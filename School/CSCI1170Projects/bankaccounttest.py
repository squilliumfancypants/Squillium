import bankaccount

def main():
    #Get the starting balance

    start_bal=float(input('Enter the starting balance: '))
    print()

    #Create a BankAccount object

    savings=bankaccount.BankAccount(start_bal)
    print('Would you like to view your account options?')
    print()
    choice=input('Enter Y/y for yes or N/n for no.')
    print()
    while choice.lower()=='y':
        print('Your balance is: $',format(savings.get_balance(),'.2f'))
        print()
        choice2=input('To make a deposit, enter D/d. To make a withdrawal, enter W/w')
        print()
        if choice2.lower()=='d':
            depam=float(input('Enter the deposit amount: '))
            savings.deposit(depam)
            print()
            print('Your balance is: ',format(savings.get_balance(),'.2f'))
            print()

        if choice2.lower()=='w':
            witam=float(input('Enter the amount you would like to witdraw: '))
            savings.withdraw(witam)
            print()
            print('Your balance is: $',format(savings.get_balance(),'.2f'))
            print()
        print('Would you like to view your account options?')
        print()
        choice=input('Enter Y/y for yes or N/n for no.')
        
main()            

        
    
