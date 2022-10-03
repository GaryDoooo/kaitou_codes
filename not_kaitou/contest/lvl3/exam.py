def gcd(a, b):
    #  print(a, b)
    if (a < b):
        a, b = b, a
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)


def lcm(a, b):
    return a * b / gcd(a, b)


l1 = list(map(int, input().split(' ')))
if len(l1) < 4:
    l2 = list(map(int, input().split(' ')))
else:
    l2 = []
[n, a, b, c] = l1 + l2
#  print(lcm(a, b), lcm(c, b), lcm(a, c))
print("%d" % (n - (n // a + n // b + n // c - n // lcm(a, b) -
                   n // lcm(a, c) - n // lcm(b, c) + n // lcm(a, lcm(b, c)))))
