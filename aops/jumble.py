# Python Class 2710
# Lesson 2 Problem 4 Part (b)
# Author: kaitou_e (774296)

from itertools import permutations

wordlist = []
f = open("wordlist.txt", "r")
for w in f:
    wordlist.append(w[:-1])


def anagrams(s):
    return permutations(s)


def jumble_solve(s):
    anagrams_s = anagrams(s)
    res = []
    for i in anagrams_s:
        if "".join(i).lower() in wordlist:
            res.append("".join(i))
    return list(set(res))


print(jumble_solve("CHWAT"))
print(jumble_solve("RAROM"))
print(jumble_solve("CEPLIN"))
print(jumble_solve("YAFLIM"))