eats(X,Y) :- animal(X,Y).
herbivore(X) :- eats(X,grass).
carnivore(X) :- eats(X,Y), eats(Y,grass).
food(Y) :- eats(X,Y).
is_bigger(X,Y) :- bigger(X,Y).
is_bigger(X,Z) :- bigger(X,Y), is_bigger(Y,Z).

animal(rabbit,grass).
animal(wolf,rabbit).
animal(bear,rabbit).

bigger(bear,rabbit).
bigger(rabbit,mouse).
bigger(wolf,mouse).