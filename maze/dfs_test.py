m = [
    "########", \
    "# # #  e", \
    "# ### ##", \
    "# #    #", \
    "# #### #", \
    "s      #", \
    "########"
    ]
from maze import maze


def assert_equals(a, b, msg=""):
    if a == b:
        print(f"Test passed: Input {b}, output {a} ")
    else:
        print(f"{a} should equal {b}: {msg}")


assert_equals(maze(m), [
    'right', 'right', 'right', 'right', 'right', 'right', 'up', 'up', 'left',
    'up', 'up', 'right', 'right'
])

# # describe("Simple cases")
# maze = ["k"]
# assert_equals(has_exit(maze), True, "simplest case")

# maze = ["###",
#         "#k#",
#         "###"]
# assert_equals(has_exit(maze), False, "no exit case")

# maze = ["###",
#         "#k ",
#         "###"]
# assert_equals(has_exit(maze), True, "single exit case")

# # maze = ["k ",
# #         "kk"]

# # expect_error("There should no be multiple Kates", lambda: has_exit(maze))

# # describe("More difficult cases")

# maze = ["########",
#         "# # ####",
#         "# #k#   ",
#         "# # # ##",
#         "# # # ##",
#         "#      #",
#         "########"]
# assert_equals(has_exit(maze), True, "single exit big maze")

# maze = ["########",
#         "# # ## #",
#         "# #k#  #",
#         "# # # ##",
#         "# # #  #",
#         "#     ##",
#         "########"]
# assert_equals(has_exit(maze), False, "no exit big maze")
