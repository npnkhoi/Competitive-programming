# Global variables
SIZE = 8
pos = [-1] * SIZE
row_mark = [False] * SIZE
diag1_mark = [False] * (2 * SIZE - 1)
diag2_mark = [False] * (2 * SIZE - 1)
sol_index = 0

# Functions

def toggle(row, col):
    if pos[col] == -1:
        # mark
        pos[col] = row
        row_mark[row] = True
        diag1_mark[row - col + SIZE - 1] = True
        diag2_mark[row + col] = True
    else:
        # unmark
        pos[col] = -1
        row_mark[row] = False
        diag1_mark[row - col + SIZE - 1] = False
        diag2_mark[row + col] = False

def backtrack(pos, col):
    if (col == SIZE):
        global sol_index
        sol_index += 1
        print('', sol_index, end='      ')
        for row in pos:
            print(row + 1, end=' ')
        print()
        return

    if pos[col] != -1:
        backtrack(pos, col + 1)
        return

    for row in range(SIZE):
        if row_mark[row] or diag1_mark[row - col + SIZE - 1] or diag2_mark[row + col]:
            continue
        toggle(row, col)
        backtrack(pos, col + 1)
        toggle(row, col)

# Main
n_test = int(input())

for i_test in range(n_test):
    sol_index = 0
    input() # read blank line
    row, col = map(int, input().split())

    row -= 1
    col -= 1
    toggle(row, col)

    print('SOLN       COLUMN')
    print(" #      1 2 3 4 5 6 7 8\n")
    backtrack(pos, 0)
    toggle(row, col)
    
    if i_test != n_test - 1:
        print()