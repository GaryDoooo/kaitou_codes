# Python Class 2710
# Lesson 2 Problem 4 Part (a)
# Author: kaitou_e (774296)
from itertools import permutations


def permute(inputList):
    """permute(inputList) -> list
    returns list of all permutations of inputList"""
    # you have to fill in the rest!
    return permutations(inputList)


# test cases
print(permute([1, 2]))
# should print [[1,2], [2,1]] in some order
print(permute([1, 2, 3]))
# should print [[1,2,3], [1,3,2], [2,1,3], [3,1,2], [2,3,1], [3,2,1]] in some order