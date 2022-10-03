from ans import has_exit

def assert_equals(a,b,msg=""):
        print(a,b,a==b,msg)

# describe("Simple cases")
maze = ["k"]
assert_equals(has_exit(maze), True, "simplest case")

maze = ["###",
        "#k#",
        "###"]
assert_equals(has_exit(maze), False, "no exit case")

maze = ["###",
        "#k ",
        "###"]
assert_equals(has_exit(maze), True, "single exit case")

# maze = ["k ",
#         "kk"]

# expect_error("There should no be multiple Kates", lambda: has_exit(maze))

# describe("More difficult cases")

maze = ["########",
        "# # ####",
        "# #k#   ",
        "# # # ##",
        "# # # ##",
        "#      #",
        "########"]
assert_equals(has_exit(maze), True, "single exit big maze")

maze = ["########",
        "# # ## #",
        "# #k#  #",
        "# # # ##",
        "# # #  #",
        "#     ##",
        "########"]
assert_equals(has_exit(maze), False, "no exit big maze")

