def I(): return map(int, input().split())


P = print
n, m, k = I()
m += 1
K = m * [0]
G = -~n * K
# ~n is bitwise reverse, 1 becomes -2, 2 becomes -3
# -~n is a shorter way for (n+1)
# K is a list with m+1 0, which sorts result, each girl's pick
# G is a list with (m+1)*(n+1) 0
while k:
    a, b = I()
    G[a * m + b] = 1  # G is the matrix of connection
    k -= 1


def D(s):  # V ensures each girl consider once during each boy's searching
    for e in range(m):
        if G[s * m + e] and V[e]:
            V[e] = 0
            # K[e]==0 the girl is not picked, D(K[e]) means the boy picked this
            # girl can have another choice.
            if K[e] < 1 or D(K[e]):
                K[e] = s
                return 1
    return 0


x = 0
while n:
    V = m * [1]  # all girls available at beginning of searching of each boy
    x += D(n)  # x is the pair counter
    n -= 1
P(x)
while m:
    m -= 1
    if K[m]:
        P(K[m], m)
