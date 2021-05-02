# # Python Class 2710
# # Lesson 3 Problem 5
# # Author: kaitou_e (774296)


class Jar:
    """ Represents a jar that can be emptied and filled in specific ways """

    def __init__(
        self, size
    ):  # Note on doc strings: I know that the \n isn't needed; but it makes the func peek in vsc look better  :)
        """Jar(size) -> Jar:\n
        Contructs a jar \n
        size: int maximum amount of water that can be contained in the jar"""
        self.size = size
        self.water = 0

    def __str__(self):
        """str(Jar) -> str:\n
        Returns a string with the Jar size and the amount of water in the jar"""
        return f"a {self.size}-liter jar with {self.water} liters of water"

    def fill_jar(self):
        """Jar.fill_jar() -> void:\n
        Fills the jar by setting the water attribute equal to size"""
        self.water = self.size

    def empty_jar(self):
        """Jar.empty_jar() -> void:\n
        Empties the jar by setting the water attribute equal to 0"""
        self.water = 0

    def pour(self, j):
        """Jar.pour(j) -> void:\n
        Pours the maximum amount of water from Jar into j\n
        j: Jar jar that will receive water"""
        if j.size - j.water < self.water:
            self.water -= j.size - j.water
            j.fill_jar()
        else:
            j.water += self.water
            self.empty_jar()


def main():
    liter5_jar = Jar(5)
    liter3_jar = Jar(3)
    liter3_jar.fill_jar()  # 0 3
    liter3_jar.pour(liter5_jar)  # 3 0
    liter3_jar.fill_jar()  # 3 3
    liter3_jar.pour(liter5_jar)  # 5 1
    liter5_jar.empty_jar()  # 0 1
    liter3_jar.pour(liter5_jar)  # 1 0
    liter3_jar.fill_jar()  # 1 3
    liter3_jar.pour(liter5_jar)  # 4 0
    print(liter5_jar)


main()