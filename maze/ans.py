from copy import deepcopy


def out(kx, ky, m):
    h = len(m)
    w = len(m[0])
    v = list(zip(*m))
    if "k" in m[0] or "k" in m[-1]:
        return True
    if "k" in v[0] or "k" in v[-1]:
        return True
    return False


def has_exit(m):
    print("")
    print("\n".join(m))
    if ("".join(m)).count("k") != 1:
        raise valueError("There should not be multiple kates")
    h = len(m)
    w = len(m[0])
    for r in m:
        if "k" in r:
            kx = r.index("k")
            ky = m.index(r)
            break
    if out(kx, ky, m):
        return True
    m = [list(i) for i in m]
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nkx = kx + dx
        nky = ky + dy
        if m[nky][nkx] == "#":
            continue
        nm = deepcopy(m)
        nm[ky][kx] = "#"
        nm[nky][nkx] = "k"
        if has_exit(["".join(i) for i in nm]):
            return True
    return False
