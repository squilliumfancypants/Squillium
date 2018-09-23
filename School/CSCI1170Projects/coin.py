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
