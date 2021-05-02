def catalan(n):
    """catalan(n) -> int
    returns C_n, the nth Catalan number"""
    e = [1]
    for k in range(1, n + 1):
        total = 0
        for i in range(k):
            total += e[i] * e[k - 1 - i]
        e.append(total)
    return e[n]


print(catalan(30))
