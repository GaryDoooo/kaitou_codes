from random import randint
from statistics import mean, stdev


def test():
    l = []
    for i in range(10001):
        l.append(randint(1, 10000))
    global_mean = mean(l)
    global_stdev = stdev(l)
    #  print("Global mean", global_mean, "stdev", global_stdev,
    #        "SEM by global_stdev", global_stdev / 10)

    s = []
    for i in range(100):
        s.append(l[randint(0, 10000)])
    SEM_s = stdev(s) / 10
    #  print("stdev of 10", stdev(s))
    #  print("SEM", stdev(s) / 10)

    ss = []
    for i in range(100):
        s = 0
        for j in range(100):
            s += l[randint(0, 10000)]
        ss.append(s / 100)
    #  print("SEM", stdev(ss))
    return abs(global_stdev / 10 - stdev(ss)) <= abs(SEM_s - stdev(ss))


ll = []
for i in range(50):
    l = []
    for i in range(50):
        l.append(test())
    ll.append(mean(l))
print("ll", mean(ll))
