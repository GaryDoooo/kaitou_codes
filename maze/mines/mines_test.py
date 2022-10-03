from mines_ans import solve


def assert_equals(a, b, msg=""):
    if a == b:
        print(f"Test passed: Input {b}, output {a} ")
    else:
        print(f"{a} should equal {b}: {msg}")


minemap = [[True]]

# ('Should return an empty array, since we\'re already at the goal')
assert_equals(solve(minemap, {"x": 0, "y": 0}, {"x": 0, "y": 0}), [])

# ('A pretty simple map (2x2)')
minemap = [[True, False], [True, True]]

# ('Should return the only correct move')
assert_equals(solve(minemap, {"x": 0, "y": 0}, {"x": 1, "y": 0}), ["right"])

# ('Should return the only moves necessary')
assert_equals(solve(minemap, {
    "x": 0,
    "y": 0
}, {
    "x": 1,
    "y": 1
}), ["right", "down"])

# ('A linear map(1x4)')
minemap = [[True], [True], [True], [True]]

# ('Should return a chain of moves to the right')
assert_equals(solve(minemap, {
    "x": 0,
    "y": 0
}, {
    "x": 3,
    "y": 0
}), ["right", "right", "right"])

# ('Should return a chain of moves to the left')
assert_equals(solve(minemap, {
    "x": 3,
    "y": 0
}, {
    "x": 0,
    "y": 0
}), ["left", "left", "left"])

# ('Should walk around an obstacle (3x3 map)')
minemap = [[True, True, True], [False, False, True], [True, True, True]]

# ('Should return the right sequence of moves')
assert_equals(
    solve(minemap, {
        "x": 0,
        "y": 0
    }, {
        "x": 2,
        "y": 0
    }),
    ["down", "down", "right", "right", "up", "up"],
)
