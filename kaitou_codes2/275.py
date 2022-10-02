from functools import lru_cache
n = int(input())
ta = input()
a = [0] + [int(x) for x in ta.split(' ')]

ra = [0] + list(reversed(a))
ra.pop()

@lru_cache(maxsize=None)
def rec(i):
    if (i <= 0): return 0
    m = 1e9
    for e in range(0, i):
        if (a[e] < a[i]):
            m = min(m, rec(e) + (i-e-1))
    return m


@lru_cache(maxsize=None)
def recr(i):
    if (i <= 0): return 0
    m = 1e9
    for e in range(0, i):
        if (ra[e] < ra[i]):
            m = min(m, recr(e) + (i-e-1))
    return m


ans = 1e9
for i in range(1, n+1):
    ans = min(ans, rec(i) + recr(n-i+1))


print(ans)