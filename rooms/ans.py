def room2(m, sx, sy):
    ans = 1
    m[sy][sx] = 1
    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        nsx = sx + dx
        nsy = sy + dy
        if nsy < 0 or nsy >= len(m) or nsx < 0 or nsx >= len(m[0]):
            continue
        if m[nsy][nsx] == 1:
            continue
        res = room(m, nsx, nsy)
        ans += res
    return ans


def room(m, x, y):
    todo = [(x, y)]
    m[y][x] = 1
    total = 1
    while todo:
        for e in m:
            print(e)
        print(total)
        print("")
        xx, yy = todo[-1]
        todo.pop()

        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nsy = yy + dy
            nsx = xx + dx
            if nsy < 0 or nsy >= len(m) or nsx < 0 or nsx >= len(m[0]):
                continue
            if m[nsy][nsx] == 0:
                total += 1
                m[nsy][nsx] = 1
                todo.append((nsx, nsy))
    return total


def biggest_room_area(l):
    rooms = []
    for y in range(len(l)):
        for x in range(len(l[y])):
            if l[y][x] == 0:
                rooms.append(room(l, x, y))

    return max(rooms)