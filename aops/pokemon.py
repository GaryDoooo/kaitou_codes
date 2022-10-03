# Python Class 2710
# Lesson 4 Problem 3
# Author: kaitou_e (774296)

import random


class Pokemon:
    def __init__(self, name, max_hp, atk, defence):
        self.name = name
        self.max_hp = max_hp
        self.hp = max_hp
        self.atk = atk
        self.defence = defence

    def __str__(self):
        return f"""{self.name} ({self.hp})
        ATK: {self.atk}  DEF: {self.defence}"""

    def calculate_dmg(self, target):
        r = random.uniform(0.85, 1)
        return (2.4 * (self.atk / target.defence)) * r

    def attack(self, target):
        dmg = int(self.calculate_dmg(target))
        if target.hp - dmg <= 0:
            print(f"{target.name} has fainted.")
        else:
            target.hp -= dmg
            print(f"{target.name} has taken {dmg} damage from {self.name}.")


# Create 2 Pokemon
b = Pokemon("Bulbasaur", 10, 100, 49)
print(b)
c = Pokemon("Charmander", 10, 100, 43)
print(c)

# A couple attacks, notice that health drops
c.attack(b)
print(b)
b.attack(c)
print(c)

# Really long battle sequence because level 1 Pokemon are weak
c.attack(b)
b.attack(c)

c.attack(b)
b.attack(c)

c.attack(b)
b.attack(c)

c.attack(b)
b.attack(c)

c.attack(b)
b.attack(c)

c.attack(b)
b.attack(c)

c.attack(b)
b.attack(c)
print(c)

# Check that fainting works
c.attack(b)
print(b)
b.attack(c)
