# Python Class 2710
# Lesson 4 Problem 4
# Author: kaitou_e (774296)

# Python Class 2710
# Lesson 4 Problem 2
# Author: kaitou_e (774296)

import random


class Die:
    """Die class"""

    def __init__(self, sides=6):
        """Die(sides)
        creates a new Die object
        int sides is the number of sides
        (default is 6)
        -or- sides is a list/tuple of sides"""
        # if an integer, create a die with sides
        #  from 1 to sides
        if isinstance(sides, int):
            self.numSides = sides
            self.sides = list(range(1, sides + 1))
        else:  # use the list/tuple provided
            self.numSides = len(sides)
            self.sides = list(sides)
        # roll the die to get a random side on top to start
        self.roll()

    def __str__(self):
        """str(Die) -> str
        string representation of Die"""
        return (
            "A "
            + str(self.numSides)
            + "-sided die with "
            + str(self.get_top())
            + " on top"
        )

    def roll(self):
        """Die.roll()
        rolls the die"""
        # pick a random side and put it on top
        self.top = random.choice(self.sides)

    def get_top(self):
        """Die.get_top() -> object
        returns top of Die"""
        return self.top

    def set_top(self, value):
        """Die.set_top(value)
        sets the top of the Die to value
        Does nothing if value is illegal"""
        if value in self.sides:
            self.top = value


def print_die(l):
    for d in l:
        print(d.get_top(), end=" ")


def reroll(d, t):
    for n in range(len(d) - 1):
        if d[n].get_top() != t:
            d[n].roll()
            return d


def europadice():
    d = [Die([1, 2, 3, 4, 5, "W"]) for _ in range(10)]
    td = d[:]
    print_die(d)
    target = max(d, key=d.count)
    print(f"going for {target.get_top()}")
    for _ in range(3):
        input("Press any key to reroll")
        reroll(d, target)
        print_die(d)
        td = d[:]
        for i in range(len(td)):
            if td[i] == "W":
                td[i].set_top(target)
        if td == [target] * 6:
            print("You win!")
            return


europadice()