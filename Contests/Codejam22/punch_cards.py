t = int(input())

for case in range(t):
    print(f'Case #{case+1}:')
    r, c = map(int, input().split())
    for i in range(2*r+1):
        for j in range(2*c+1):
            if i <= 1 and j <= 1:
                to_print = '.'
            else:
                CHAR_TABLE = [['+', '-'], ['|', '.']]
                to_print = CHAR_TABLE[i % 2][j % 2]
            print(to_print, end='')
        print()
