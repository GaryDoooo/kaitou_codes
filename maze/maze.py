from copy import deepcopy


def maze(m):
    print("")
    print("\n".join(["".join(i) for i in m]))
    if ("".join(m)).count("s") != 1:
        raise ValueError("There should not be multiple s")
    h = len(m)
    w = len(m[0])
    for r in m:
        if "s" in r:
            kx = r.index("s")
            ky = m.index(r)
            break
    m = [list(i) for i in m]
    for dx, dy, dir in [(1, 0, "right"), (-1, 0, "left"), (0, 1, "down"),
                        (0, -1, "up")]:
        nkx = kx + dx
        nky = ky + dy
        try:
            if m[nky][nkx] == "#":
                continue
            if m[nky][nkx] == "e":
                return [dir]
        except:
            continue
        nm = deepcopy(m)
        nm[ky][kx] = "#"
        nm[nky][nkx] = "s"
        res = maze(["".join(i) for i in nm])
        if res:
            return [dir] + res
    return False