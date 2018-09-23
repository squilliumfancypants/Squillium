import random

class Coin:
    
    #The __init__ method initializes the sideup
    #data attribute with 'Heads'.

    def __init__(self):
        self.__sideup='Heads'
        
    #The toss method simulates a coin toss by randomly
    #assigning 'Heads' or 'Tails' to the sideup method, using randint

    def toss(self):
        if random.randint(0,1)==0:
            self.__sideup='Heads'
        else:
            self.__sideup='Tails'

    def get_sideup(self):
        return self.__sideup

def main():

    #Create an object named 'my_coin' of the Coin class
    
    my_coin=Coin()

    #Toss the coin using the toss method. This assigns a new value to my_coin

    print('I am tossing the coin')
    my_coin.toss()

    #Cheat and set the coin to 'Heads'
    #Notice this doesn't work because sideup method
    #was made private by changing it to __sideup
    
    my_coin.__sideup='Heads'

    #Return the value of the coin toss using the get_sideup method, and
    #print the result

    print('This side is up:',my_coin.get_sideup())

main()
    
    
            
