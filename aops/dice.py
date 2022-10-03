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

            # Add a method to the $\verb#Die#$ class from the lesson.

    # The new method flips the die over.
    #  You can simulate this by replacing the top number on the die with the same position if we
    # reversed the $\verb#sides#$ list. (You can assume that all the values on the Die are different.)
    def flip(self):
        self.top = (self.sides[:])[::-1][(self.sides).index(self.top)]


d = Die()
d.set_top(6)
print(d)
d.flip()
print(d)
