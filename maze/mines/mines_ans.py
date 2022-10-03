from copy import deepcopy


def solve(map, miner, exit):
    # print("")
    # print("miner:", miner)
    # print("exit:", exit)
    # print("\n".join(" ".join([str(i) for i in e]) for e in map))
    if miner == exit:
        return []
    for ny, nx, dir in [
        (0, 1, "right"),
        (0, -1, "left"),
        (-1, 0, "up"),
        (1, 0, "down"),
    ]:
        nxm = miner["x"] + nx
        nxy = miner["y"] + ny
        if nxm < 0 or nxy < 0:
            continue
        try:
            # if nxy == exit["y"] and nxm == exit["x"]:
            #     return [dir]
            if map[nxm][nxy] == False:
                continue
        except:
            continue
        nm = deepcopy(map)
        nm[miner["x"]][miner["y"]] = False
        # print("\n nm:")
        # print("\n".join(" ".join([str(i) for i in e]) for e in nm))
        res = solve(nm, {"x": nxm, "y": nxy}, exit)
        if res != None:
            return [dir] + res
    return None