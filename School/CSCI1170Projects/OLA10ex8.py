def drawBar():
    symbol=input("Enter a symbol: ")
    height=int(input("Enter a number: "))
    width=int(input("Enter the width: "))
    for i in(height,width):
        print(symbol, sep='',end='x')
        

drawBar()
