class Solution:
    # Global variables
    def toggle(self, row, col):
        if self.pos[row] == -1:
            # mark
            self.pos[row] = row
            self.col_mark[col] = True
            self.diag1_mark[row - col + self.size - 1] = True
            self.diag2_mark[row + col] = True
        else:
            # unmark
            self.pos[row] = -1
            self.col_mark[col] = False
            self.diag1_mark[row - col + self.size - 1] = False
            self.diag2_mark[row + col] = False

    def is_occupied(self, row, col):
        # print(type(row), row)
        return (self.col_mark[col]
                or self.diag1_mark[row - col + self.size - 1] 
                or self.diag2_mark[row + col])

    def backtrack(self, row):
        print('backtrack', row, self.pos)
        if (row == self.size):
            self.sol.append(self.pos[:])
            return

        for col in range(self.size):
            if self.is_occupied(row, col):
                continue

            self.toggle(row, col)
            self.backtrack(row + 1)
            self.toggle(row, col)

    def solveNQueens(self, n: int):
        self.size = n
        self.pos = [-1] * self.size
        self.col_mark = [False] * self.size
        self.diag1_mark = [False] * (2 * self.size - 1)
        self.diag2_mark = [False] * (2 * self.size - 1)
        self.sol = []

        self.backtrack(0)
        return self.sol

sol = Solution()
print(sol.solveNQueens(4))
