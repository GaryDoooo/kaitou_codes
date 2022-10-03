from functools import lru_cache

n = int(input())
@lru_cache(maxsize=None)
def rec(s):
    if s == 1: return 1
    if s == 2: return 2
    if s == 3: return 4
    return (rec(s-3) + rec(s-2) + rec(s-1))%1000000007

print(rec(n))