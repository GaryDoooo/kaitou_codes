# Python Class 2710
# Lesson 5 Problem 4
# Author: kaitou_e (774296)

import random


class Domino:
    def __init__(self, a, b):
        """Domino(a,b) -> Domino
        creates the domino a-b"""
        self.sides = (a, b)

    def __str__(self):
        """str(Domino) -> str"""
        return str(self.sides[0]) + "-" + str(self.sides[1])

    def reverse_str(self):
        """Domino.reverse_str() -> str
        string with sides reversed"""
        return str(self.sides[1]) + "-" + str(self.sides[0])

    def get_sides(self):
        """Domino.get_sides() -> tuple
        returns the sides of the domino"""
        return self.sides

    def reverse(self):
        """Domino.reverse()
        reverses the sides"""
        (a, b) = self.sides
        self.sides = (b, a)

    def is_match(self, pip):
        """Domino.is_match(pip) -> int
        checks if the domino matches the given pip
        returns the index (0 or 1) of the half that matches
        returns -1 if not a match"""
        if self.sides[0] == pip:
            return 0
        elif self.sides[1] == pip:
            return 1
        else:
            return -1


class DominoSet:
    def __init__(self):
        """DominoSet() -> DominoSet"""
        self.dominoes = []
        for a in range(7):
            for b in range(a, 7):
                self.dominoes.append(Domino(a, b))
        random.shuffle(self.dominoes)

    def deal(self):
        """DominoSet.deal() -> list
        returns a list of 7 dominoes"""
        return [self.dominoes.pop() for i in range(7)]


class Chain:
    """represents a domino chain
    attributes:
      chain: a list of dominoes"""

    def __init__(self):
        """Chain() -> Chain
        start a new domino chain with the 6-6 domino"""
        self.chain = [Domino(6, 6)]

    def __str__(self):
        """str(Chain) -> str"""
        return ",".join([str(d) for d in self.chain])

    def left_end(self):
        """Chain.left_end() -> int
        returns the number on the left end of the chain"""

        return self.chain[0].get_sides()[0]

    def right_end(self):
        """Chain.right_end() -> int
        returns the number on the right end of the chain"""

        return self.chain[-1].get_sides()[1]

    def is_playable(self, domino):
        """Chain.is_playable(Domino) -> boolean
        returns True if the domino can be played on either end
          of the chain, False if not"""

        return (
            domino.is_match(self.left_end()) >= 0
            or domino.is_match(self.right_end()) >= 0
        )

    def add(self, domino, rightOnly=False):
        """Chain.add(domino)
        adds a domino to the chain
        does nothing if the domino cannot be added
        if rightOnly is True, only plays on the right side"""

        if not rightOnly and domino.is_match(self.left_end()) == 0:

            domino.reverse()
            self.chain.insert(0, domino)
        elif not rightOnly and domino.is_match(self.left_end()) == 1:

            self.chain.insert(0, domino)
        elif domino.is_match(self.right_end()) == 0:

            self.chain.append(domino)
        elif domino.is_match(self.right_end()) == 1:

            domino.reverse()
            self.chain.append(domino)


class Player:
    """represents a dominoes player
    attributes:
      isHuman: True if human, False if computer
      hand: a Hand"""

    def __init__(self, isHuman, dominoes):
        """Player(isHuman,dominoes) -> Player
        creates a new player with a 7-domino hand taken from dominoes
        isHuman is True for a human player, False for a computer player"""
        self.isHuman = isHuman
        self.hand = dominoes.deal()

    def __str__(self):
        """str(Player) -> str"""
        if self.isHuman:
            return "You have " + str(len(self.hand)) + " dominoes"
        else:
            return "A computer player has " + str(len(self.hand)) + " dominoes"

    def is_human(self):
        """Player.is_human() -> boolean
        returns True for a human player, False for a computer player"""
        return self.isHuman

    def goes_first(self):
        """Player.goes_first() -> boolean
        makes first move and returns True if player has 6-6
        returns False otherwise"""
        for domino in self.hand:
            if domino.get_sides()[0] == 6 and domino.get_sides()[1] == 6:
                self.hand.remove(domino)
                return True
        return False

    def has_won(self):
        """Player.has_won() -> boolean
        returns True if the player has won, False otherwise"""

        return len(self.hand) == 0

    def take_turn(self, chain):
        """Player.take_turn(chain) -> boolean
        takes the player's turn in the game
        chain is the current chain
        returns True if the player passes, False otherwise"""
        if self.isHuman:

            print("It's your turn.")
            print("The current chain:")
            print(chain)
            print("Your hand:")
            print(
                "\n".join([str(self.hand.index(d)) + ": " + str(d) for d in self.hand])
            )

            while True:
                choice = input("Which do you want to play? Enter p to pass. ")
                if choice.lower() == "p":
                    break
                if choice.isdigit():

                    if int(choice) < 0 or int(choice) >= len(self.hand):
                        print("Invalid domino number!")
                    elif not chain.is_playable(self.hand[int(choice)]):
                        print("That domino is not playable!")
                    else:
                        break

            if choice.isdigit():
                choice = int(choice)
                domino = self.hand.pop(choice)
                rightOnly = False

                if (
                    domino.is_match(chain.left_end()) >= 0
                    and domino.is_match(chain.right_end()) >= 0
                ):
                    print("That domino matches both sides of the chain.")
                    response = "x"
                    while response.lower() not in "lr":
                        response = input(
                            "Which side do you want to play it on? (Type l or r) "
                        )
                    if response.lower() == "r":
                        rightOnly = True
                chain.add(domino, rightOnly)
                return False
            else:
                return True

        else:

            playlist = [d for d in self.hand if chain.is_playable(d)]

            if len(playlist) > 0:

                domino = playlist[random.randrange(len(playlist))]
                self.hand.remove(domino)
                chain.add(domino)
                print(
                    "Computer player plays "
                    + str(domino)
                    + ", has "
                    + str(len(self.hand))
                    + " dominoes remaining."
                )
                return False

            else:
                print(
                    "Computer player passes"
                    + ", has "
                    + str(len(self.hand))
                    + " dominoes remaining."
                )
                return True


def play():
    """play_solo() -> number
    plays dominoes with 1 human and 3 computer players
    returns player number of winner (human = 0)"""

    dominoes = DominoSet()
    chain = Chain()

    playerList = [Player(True, dominoes)]

    for i in range(3):
        playerList.append(Player(False, dominoes))

    for i in range(4):
        if playerList[i].goes_first():
            if playerList[i].is_human():
                print("You went first by placing 6-6.")
            else:
                print("A computer player went first by placing 6-6.")
            currentPlayerNum = (i + 1) % 4

    passCount = 0
    while True:
        player = playerList[currentPlayerNum]
        passed = player.take_turn(chain)
        if passed:
            passCount += 1
        else:
            passCount = 0
        if player.has_won() or passCount == 4:

            if player.is_human():
                print("You won!")
            else:
                print("Sorry, a computer player won.")
            return currentPlayerNum

        currentPlayerNum = (currentPlayerNum + 1) % 4


play()