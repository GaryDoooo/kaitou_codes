import re

res = []
for i in range(1, 21):
    res.append(bin(i)[2:])

pattern = '.$'
for s in res:
    if re.findall(pattern, s):
        print(s, int(s, 2))
