#import custom module 'coin'

import coin

def main():

    #create an object of the Coin class
    my_coin=coin.Coin()

    #toss the coin

    print('Tossing the coin...')
    my_coin.toss()

    #print the result of the coin toss

    print('The coin landed on:',my_coin.get_sideup())

main()

