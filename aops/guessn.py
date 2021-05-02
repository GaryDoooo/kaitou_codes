from random import randint

n = int(input("Choose a num: "))
high = 100
low = 0
while 1:
    print(f"I guess the num is {(high+low)/2}")
    inp = input("Too high or too low? (input high, low or correct): ")
    if inp.lower() == "correct":
        print(":)")
        exit(0)
    if inp.lower() == "high":
        high = (high + low) / 2
    if inp.lower() == "low":
        low = (high + low) / 2
    else:
        print("Please input a valid input")
