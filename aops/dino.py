# Python Class 2710
# Lesson 6 Problem 5
# Author: kaitou_e (774296)

import random

### Die class that we previously wrote ###


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
        self.top = self.sides[random.randrange(self.numSides)]

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


### end Die class ###


class DinoDie(Die):
    """implements one die for Dino Hunt"""

    ### you need to add the code ###
    def __init__(self, color):
        if color == "green":
            Die.__init__(self, sides=["d", "d", "d", "l", "l", "f"])
        if color == "red":
            Die.__init__(self, sides=["d", "l", "l", "f", "f", "f"])
        if color == "yellow":
            Die.__init__(self, sides=["d", "d", "l", "l", "f", "f"])


class DinoPlayer:
    """implements a player of Dino Hunt"""

    ### you need to add the code ###
    def __init__(self, name):
        self.name = name
        self.score = 0
        self.dice = []
        self.reset_dice()

    def __str__(self):
        return f"{self.name} has {self.score} points."  # py 3.6+

    def get_name(self):
        return self.name

    def get_amount_dice(self):
        return len(self.dice)

    def get_score(self):
        return self.score

    def reset_dice(self):
        """Resets the player's dice in their pile"""
        self.dice = []
        for i in range(1, 14):
            if i <= 3:
                self.dice.append(DinoDie("red"))
            elif i <= 7:
                self.dice.append(DinoDie("yellow"))
            else:
                self.dice.append(DinoDie("green"))

    def stomp(self, d):
        self.score -= d
        print("You got stomped!")

    def play(self):
        """Play a move. Includes choosing dice randomly and playing them.
        Returns number of dinos, leaves, and feet rolled respectively"""
        d = []
        # print(self.dice)
        for i in range(3 if self.get_amount_dice() >= 3 else len(self.dice)):
            d.append(
                self.dice.pop(self.dice.index(random.choice(self.dice)))
            )  # choose 3 random dice
        for i in d:
            print("  ", i)
        dino, l, f = 0, 0, 0
        for die in d:  # count the die
            die.roll()
            if die.get_top() == "d":
                dino += 1
            if die.get_top() == "l":
                l += 1
            if die.get_top() == "f":
                f += 1
        self.score += dino
        return dino, l, f


def play_dino_hunt(numPlayers, numRounds):
    """play_dino_hunt(numPlayer,numRounds)
    plays a game of Dino Hunt
      numPlayers is the number of players
      numRounds is the number of turns per player"""
    ### you need to add the code ###
    player_list = []
    for n in range(numPlayers):
        name = input(f"Player {n+1}, enter your name: ")  # py 3.6+
        player_list.append(DinoPlayer(name))  # ask for name then add player

    for r in range(1, numRounds + 1):
        print("ROUND", r)  # print round num
        for p in player_list:
            print(p)  # print every player's score
        for p in player_list:
            print(p.get_name(), ", it's your turn")
            print("You have", p.get_amount_dice(), "dice left")
            input("Press enter to roll")
            d, l, f = p.play()
            print(f"This turn so far: {d} dinos, {l} leaves, {f} feet")
            while 1:  # while the player still can reroll and wants to reroll
                print("You have", p.get_amount_dice(), "dice left")
                reroll = input("Do you want to reroll? (y/n)  ")
                if (
                    p.get_amount_dice() == 0 or reroll == "n"
                ):  # exit if the player has no dice or doesn't want to reroll
                    break
                if reroll == "y":
                    turn = list(
                        p.play()
                    )  # reroll then add num of dinos, leaves, and feet
                    d += turn[0]
                    l += turn[1]
                    f += turn[2]
                    print(f"This turn so far: {d} dinos, {l} leaves, {f} feet")
                    p.reset_dice()
                    if f >= 3:  # if got stomped
                        p.stomp(d)
                        break  # move onto next player/round

    winner = max(player_list, key=lambda p: p.get_score())
    print(f"Winner is {winner.get_name()} with {winner.get_score()} points!")


play_dino_hunt(2, 2)
