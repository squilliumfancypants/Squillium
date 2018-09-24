eats(X,Y) :- animal(X,Y).
herbivore(X) :- eats(X,grass).
animal(rabbit,grass).
animal(wolf,rabbit).
