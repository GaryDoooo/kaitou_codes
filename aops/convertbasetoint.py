def get_base_number(num, base, time=0):
    """get_base_number(num,base) -> int:
    returns value of num as a base number in the given base"""
    # you have to fill in the rest
    # return int(num, base)             :)
    if len(num) == 1:
        return (base ** time) * int(num)
    return ((base ** time) * int(num[-1])) + get_base_number(num[:-1], base, time + 1)


# test cases
print(get_base_number("10011", 2))  # should be 19
print(get_base_number("3202", 5))  # should be 427
print(get_base_number("611023", 7))
