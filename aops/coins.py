from functools import lru_cache
from itertools import combinations


@lru_cache()
def coins(c1, c2, c3, n):
    if n <= 0:
        return 0
    if n in [c1, c2, c3]:
        return 1
    n1 = coins(c1, c2, c3, n - c1) if n - c1 > 0 else 100
    n2 = coins(c1, c2, c3, n - c2) if n - c2 > 0 else 100
    n3 = coins(c1, c2, c3, n - c3) if n - c3 > 0 else 100
    return min(n1, n2, n3) + 1


def calc_avg_c(c1, c2, c3):
    total_c = 0
    for n in range(100):  # 0 - 99
        total_c += coins(c1, c2, c3, n)
    return total_c / 100


def find_best_c():
    c_com = list(combinations(range(2, 100), 2))
    best = calc_avg_c(1, c_com[0][0], c_com[0][1])
    best_c = [1] + list(c_com[0])
    for com in c_com[1:]:
        com = [1] + list(com)
        avg_c_com = calc_avg_c(com[0], com[1], com[2])
        if avg_c_com < best:
            best = avg_c_com
            best_c = com
    return best_c


best_pair = find_best_c()
print("1, 10, 25")
print(calc_avg_c(1, 10, 25))
print("best pair: ", best_pair)
print(calc_avg_c(best_pair[0], best_pair[1], best_pair[2]))