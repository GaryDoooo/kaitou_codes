s = input()
res = s[0].lower()
for c in s[1:]:
    if c.islower():
        res = res + c
    else:
        res = res + "_" + c.lower()
print(res)
