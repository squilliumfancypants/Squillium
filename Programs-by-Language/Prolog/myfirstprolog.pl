eat(bear,fish).
eat(bear,deer).
eat(deer,grass).
animal(bear).
animal(deer).
animal(fish).
plant(grass).
bigger(bear,dear).
bigger(bear,deer).
bigger(bear,fish).
bigger(bear,grass).
bigger(dear,grass).
bigger(fish,grass).
friendly(grass).
friendly(deer).
bigger(bear,grass).
bigger(dear,grass).
bigger(fish,grass).
friendly(grass).
hostile(bear).
hostile(bear).
future_poop(X) :- eat(Y, X).
mortal(X) :- man(X).
man(socrates).
prey(X) :- eat(Y,X) , animal(X).
