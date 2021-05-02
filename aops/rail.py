# Python Class 2710
# Lesson 1 Problem 7
# Author: kaitou_e (774296)

# putting all words in a list
wordlist = []
f = open("wordlist.txt", "r")  # open the file
for w in f:  # for every line...
    wordlist.append(
        w[:-1]
    )  # ... append the word/line to the list without the \n at the end
# and don't close the file ;)


def encipher_fence(plaintext, numRails):
    """encipher_fence(plaintext,numRails) -> str
    encodes plaintext using the railfence cipher
    numRails is the number of rails"""
    # you have to fill in the rest!
    rails = ["" for _ in range(numRails)]  # create a list with numRails empty strings
    ind = 0  # index to insert next letter into
    for i in plaintext:  # iterate through every letter
        rails[ind] += i  # Add the letter to the correct rail
        ind += (
            1 if ind < numRails - 1 else -(numRails - 1)
        )  # Increase the index if it is not yet equal to numRails, change it back to 0 otherwise
    return "".join(rails[::-1])  # return the rails joined together in reverse order


def decipher_fence(ciphertext, numRails):
    """decipher_fence(ciphertext,numRails) -> str
    returns decoding of ciphertext using railfence cipher
    with numRails rails"""
    # you have to fill in the rest!

    lr = len(ciphertext) // numRails  # find the length of one rail
    r = len(ciphertext) % numRails  # remainder
    raillens = [lr for _ in range(numRails - r)] + [
        lr + 1 for _ in range(r)
    ]  # The length of each rail
    rails = []
    cciphertext = ciphertext
    for i in raillens:  # Separate the given strings into rails using raillens
        rails.append(ciphertext[:i])
        ciphertext = ciphertext[i:]
    f = ""  # final result
    ind = 0  # to keep track of which rail to take an element out of
    rails = rails[::-1]  # reverse rails
    while len(f) < len(cciphertext):  # while not all elements from rail is put in f...
        if rails[ind] != "":  # if the rail is not empty...
            f += rails[ind][
                0
            ]  # add the first character of the string to the final string
        rails[ind] = rails[ind][1:]  # shift the string
        ind = (ind + 1) % len(rails)  # continue to cycle the index
    return f  # return result!


def decode_text(ciphertext, wordfilename):
    """decode_text(ciphertext,wordfilename) -> str
    attempts to decode ciphertext using railfence cipher
    wordfilename is a file with a list of valid words"""
    # you have to fill in the rest!

    maxr = 0  # For recording the largest number of words found when trying 10 rails
    rail = 0  # The number of rails the string has
    for i in range(1, 11):  # checking all of the possible rails
        score = 0  # number of words the string has
        decoded = decipher_fence(ciphertext, i)  # deciphered result
        for e in "!?.,;:":  # remove all (common) symbols so the words count properly
            decoded = decoded.replace(e, "")
        for w in decoded.split():  # for every "word"....
            score += (
                1 if w in wordlist else 0
            )  # ... check if the "word" is a valid eng word (wordlist defined at beginning of code)
        if score > maxr:  # Change the maximum score
            rail = i
            maxr = score
    return decipher_fence(ciphertext, rail)


# test cases

# enciphering
print(encipher_fence("abcdefghi", 3))
# should print: cfibehadg
print(encipher_fence("This is a test.", 2))
# should print: hsi  etTi sats.
print(encipher_fence("This is a test.", 3))
# should print: iiae.h  ttTss s
print(encipher_fence("Happy birthday to you!", 4))
# should print: pidtopbh ya ty !Hyraou
print("")
# deciphering
print(decipher_fence("hsi  etTi sats.", 2))
# should print: This is a test.
print(decipher_fence("iiae.h  ttTss s", 3))
# should print: This is a test.
print(decipher_fence("pidtopbh ya ty !Hyraou", 4))
# should print: Happy birthday to you!
print("")
# decoding
print(decode_text(" cr  pvtl eibnxmo  yghu wou rezotqkofjsehad", "wordlist.txt"))
# should print: the quick brown fox jumps over the lazy dog
print(
    decode_text("unt S.frynPs aPiosse  Aa'lgn lt noncIniha ", "wordlist.txt")
)  # It's fun learning Python in an AoPS class. ^^
# should print... we'll let you find out!