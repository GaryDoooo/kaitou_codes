import random
from unoframe import UnoFrame
import tkinter
import threading
import time

def print2(txt):
    f.addmessage(txt)

def input(text):
    print2(text)
    f.clicked = False
    f.input_value=None
    while True:
        if f.clicked:
            if f.input_value is not None:
                if len(f.input_value)>0:
                    break
    return f.input_value

# Uno classes/internal stuff -------------------------------------------------------------------
class UnoCard:
    """represents an Uno card
    attributes:
      rank: int from 0 to 9
      color: string"""

    def __init__(
        self, rank, color, reverse=False, skip=False, draw_two=False, wild=False
    ):
        """UnoCard(rank,color) -> UnoCard
        creates an Uno card with the given rank and color"""
        self.rank = rank
        self.color = color

        # set the action card
        if reverse:
            self.action = "reverse"
        elif skip:
            self.action = "skip"
        elif draw_two:
            self.action = "draw_two"
        else:
            self.action = None

    def __str__(self):
        """str(Unocard) -> str"""
        if self.rank == -2:
            return "wild card"
        return f"{self.rank if self.rank != -1 else ''} {self.color} {self.action if self.action != None else ''}"

    def is_match(self, other):
        """UnoCard.is_match(UnoCard) -> boolean
        returns True if the cards match in rank or color, False if not"""
        if other.rank == -2:
            c = input(
                """Choose a color:
            1, red
            2, blue
            3, green
            4, yellow
            (1, 2, 3, or 4): """
            )
            other.color = ["red", "blue", "green", "yellow"][c - 1]
            return True

        return (
            (self.color == other.color)
            or (self.rank == other.rank and self.rank != -1)
            or (self.action == other.action and self.action != None)
        )


class UnoDeck:
    """represents a deck of Uno cards
    attribute:
      deck: list of UnoCards"""

    def __init__(self):
        """UnoDeck() -> UnoDeck
        creates a new full Uno deck"""
        self.deck = []
        for color in ["red", "blue", "green", "yellow"]:
            self.deck.append(UnoCard(0, color))  # one 0 of each color
            self.deck.append(UnoCard(-1, color, reverse=True))
            self.deck.append(UnoCard(-1, color, reverse=True))
            self.deck.append(UnoCard(-1, color, skip=True))
            self.deck.append(UnoCard(-1, color, skip=True))
            self.deck.append(UnoCard(-1, color, draw_two=True))
            self.deck.append(UnoCard(-1, color, draw_two=True))
            self.deck.append(UnoCard(-2, -2, wild=True))
            for i in range(2):
                for n in range(1, 10):  # two of each of 1-9 of each color
                    self.deck.append(UnoCard(n, color))
        random.shuffle(self.deck)  # shuffle the deck

    def __str__(self):
        """str(Unodeck) -> str"""
        return "An Uno deck with " + str(len(self.deck)) + " cards remaining."

    def is_empty(self):
        """UnoDeck.is_empty() -> boolean
        returns True if the deck is empty, False otherwise"""
        return len(self.deck) == 0

    def deal_card(self):
        """UnoDeck.deal_card() -> UnoCard
        deals a card from the deck and returns it
        (the dealt card is removed from the deck)"""
        return self.deck.pop()

    def reset_deck(self, pile):
        """UnoDeck.reset_deck(pile) -> None
        resets the deck from the pile"""
        if len(self.deck) != 0:
            return
        self.deck = pile.reset_pile()  # get cards from the pile
        random.shuffle(self.deck)  # shuffle the deck


class UnoPile:
    """represents the discard pile in Uno
    attribute:
      pile: list of UnoCards"""

    def __init__(self, deck):
        """UnoPile(deck) -> UnoPile
        creates a new pile by drawing a card from the deck"""
        card = deck.deal_card()
        self.pile = [card]  # all the cards in the pile

    def __str__(self):
        """str(UnoPile) -> str"""
        return "The pile has " + str(self.pile[-1]) + " on top."

    def top_card(self):
        """UnoPile.top_card() -> UnoCard
        returns the top card in the pile"""
        return self.pile[-1]

    def add_card(self, card):
        """UnoPile.add_card(card) -> None
        adds the card to the top of the pile"""
        self.pile.append(card)

    def reset_pile(self):
        """UnoPile.reset_pile() -> list
        removes all but the top card from the pile and
          returns the rest of the cards as a list of UnoCards"""
        newdeck = self.pile[:-1]
        self.pile = [self.pile[-1]]
        return newdeck


class UnoPlayer:
    """represents a player of Uno
    attributes:
      name: a string with the player's name
      hand: a list of UnoCards"""

    def __init__(self, name, deck, comp=False):
        """UnoPlayer(name,deck) -> UnoPlayer
        creates a new player with a new 7-card hand"""
        self.comp = comp
        self.name = name
        self.hand = [deck.deal_card() for i in range(7)]

    def __str__(self):
        """str(UnoPlayer) -> UnoPlayer"""
        return str(self.name) + " has " + str(len(self.hand)) + " cards."

    def get_name(self):
        """UnoPlayer.get_name() -> str
        returns the player's name"""
        return self.name

    def get_hand(self):
        """get_hand(self) -> str
        returns a string representation of the hand, one card per line"""
        if not self.comp:
            output = ""
            for card in self.hand:
                output += str(card) + "\n"
            return output
        else:
            return ""

    def has_won(self):
        """UnoPlayer.has_won() -> boolean
        returns True if the player's hand is empty (player has won)"""
        return len(self.hand) == 0

    def draw_card(self, deck):
        """UnoPlayer.draw_card(deck) -> UnoCard
        draws a card, adds to the player's hand
          and returns the card drawn"""
        card = deck.deal_card()  # get card from the deck
        self.hand.append(card)  # add this card to the hand
        return card

    def play_card(self, card, pile):
        """UnoPlayer.play_card(card,pile) -> None
        plays a card from the player's hand to the pile
        CAUTION: does not check if the play is legal!"""
        self.hand.remove(card)
        pile.add_card(card)

    def take_turn(self, deck, pile):
        """UnoPlayer.take_turn(deck,pile) -> None
        takes the player's turn in the game
          deck is an UnoDeck representing the current deck
          pile is an UnoPile representing the discard pile"""
        if not self.comp:
            # print2 player info
            print2(self.name + ", it's your turn.")
            print2(pile)
            print2("Your hand: ")
            print2(self.get_hand())
            # get a list of cards that can be played
            topcard = pile.top_card()
            matches = [card for card in self.hand if card.is_match(topcard)]
            if len(matches) > 0:  # can play
                for index in range(len(matches)):
                    # print2 the playable cards with their number
                    print2(str(index + 1) + ": " + str(matches[index]))
                # get player's choice of which card to play
                choice = 0
                while choice < 1 or choice > len(matches):
                    choicestr = input("Which do you want to play? ")
                    if choicestr.isdigit():
                        choice = int(choicestr)
                # play the chosen card from hand, add it to the pile
                self.play_card(matches[choice - 1], pile)
            else:  # can't play
                print2("You can't play, so you have to draw.")
                input("Press enter to draw.")
                # check if deck is empty -- if so, reset it
                if deck.is_empty():
                    deck.reset_deck(pile)
                # draw a new card from the deck
                newcard = self.draw_card(deck)
                print2("You drew: " + str(newcard))
                if newcard.is_match(topcard):  # can be played
                    print2("Good -- you can play that!")
                    self.play_card(newcard, pile)
                else:  # still can't play
                    print2("Sorry, you still can't play.")
                input("Press enter to continue.")
        if self.comp:
            matches = [card for card in self.hand if card.is_match(pile.top_card())]
            if len(matches) > 0:
                playc = max(matches, key=lambda c: c.rank)
                self.play_card(playc, pile)
                print2(f"Computer plays {playc}")
            else:
                if deck.is_empty():
                    deck.reset_deck(pile)
                newcard = self.draw_card(deck)
                topcard = pile.top_card()
                if newcard.is_match(topcard):
                    self.play_card(newcard, pile)
                    print2(f"Computer plays {newcard}")


def play_uno(numPlayers):
    """play_uno(numPlayers) -> None
    plays a game of Uno with numPlayers"""
    # set up full deck and initial discard pile
    deck = UnoDeck()
    pile = UnoPile(deck)
    # set up the players
    playerList = []
    playerList.append(UnoPlayer("player", deck))
    playerList.append(UnoPlayer("Computer " , deck, comp=True))
    # for n in range(numPlayers):
    #     # get each player's name, then create an UnoPlayer
    #     compp = input("Will this player be a computer?(t or f): ")
    #     if compp == "f":
    #         name = input("Player #" + str(n + 1) + ", enter your name: ")
    #         playerList.append(UnoPlayer(name, deck))
    #     if compp == "t":
    #         playerList.append(UnoPlayer("Computer " + str(n+1), deck, comp=True))
    # randomly assign who goes first
    currentPlayerNum = random.randrange(numPlayers)
    # play the game
    reverse = 1  # 1 = regular order, -1 = reversed
    while True:
        # print2 the game status
        print2("-------")
        for player in playerList:
            print2(player)
        print2("-------")
        # take a turn
        playerList[currentPlayerNum].take_turn(deck, pile)
        # check for a winner
        if playerList[currentPlayerNum].has_won():
            print2(playerList[currentPlayerNum].get_name() + " wins!")
            print2("Thanks for playing!")
            break
        # go to the next player
        action = pile.top_card().action
        if action == "reverse":
            reverse *= -1
        if action == "draw_two":
            playerList[(currentPlayerNum + reverse) % numPlayers].draw_card(deck)
            playerList[(currentPlayerNum + reverse) % numPlayers].draw_card(deck)
        if action == "skip":
            currentPlayerNum = (currentPlayerNum + (reverse * 2)) % numPlayers
            continue
        currentPlayerNum = (currentPlayerNum + reverse) % numPlayers

class App(threading.Thread):

    def __init__(self):
        threading.Thread.__init__(self)
        self.start()

    def callback(self):
        self.root.quit()

    def run(self):
        self.root = tkinter.Tk()
        self.root.protocol("WM_DELETE_WINDOW", self.callback)
        ############# set widgets ~~~~~~~~~~~~~~~~~~~~~~~
        self.frame = UnoFrame(self.root)
        self.frame.pack()
        ###############################
        self.root.mainloop()



if __name__ == "__main__":

    app=App()
    time.sleep(0.3)
    r=app.root
    f=app.frame
    play_uno(2)
    
