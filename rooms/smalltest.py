from ans import biggest_room_area as a

# from full import data


def assert_equals(a, b, msg=""):
    if a == b:
        print(f"Test passed: Input {b}, output {a} ")
    else:
        print(f"{a} should equal {b}: {msg}")

    # for i, j in data[:4]:


print(assert_equals(a([[0, 0]]), 2))
