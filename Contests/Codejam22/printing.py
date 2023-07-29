tc = int(input())
TOTAL = 10**6
for case in range(tc):
    ink = [TOTAL]*4
    for _ in range(3):
        cur = list(map(int, input().split()))
        for i in range(4):
            ink[i] = min(ink[i], cur[i])
    print(f'Case #{case+1}: ', end='')
    if sum(ink) >= TOTAL:
        index = 0
        while sum(ink) > TOTAL:
            ink[index] -= min(ink[index], sum(ink) - TOTAL)
            index += 1
        for val in ink:
            print(val, end=' ')
        print()
    else:
        print("IMPOSSIBLE")
