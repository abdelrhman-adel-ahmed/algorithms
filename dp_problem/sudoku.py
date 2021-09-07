#space effient by time comnsuming o(9!^9)
board = [
    ["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"],
]


def is_valid(grid, row, col, number):
    for i in range(9):
        num = grid[row][i]

        if num == number:
            return False
    for i in range(9):
        num = grid[i][col]
        if num == number:
            return False
    """cell at row 1 col 1 -->corner will be 0,0
    and then loop over each cell in the block and check"""
    corner_row = row - row % 3
    corner_col = col - col % 3
    for i in range(3):
        for j in range(3):
            num = grid[corner_row + i][corner_col + j]
            if num == number:
                return False
    return True


def solve(grid, row, col):
    """if col ==9 mean we go through all the col 0--8 and if row is 8
    when the col is 9 that mean we finish, if just the col is 9 then we need
    to go to the next row and start from the first cell (col=0)"""
    if col == 9:
        if row == 8:
            return True
        col = 0
        row += 1
    # if current index not empty solve for next one
    if grid[row][col] != ".":
        return solve(grid, row, col + 1)

    for num in range(1, 10):
        num = str(num)
        if is_valid(grid, row, col, num):
            grid[row][col] = num

            if solve(grid, row, col + 1):
                return True

        grid[row][col] = "."

    return False


print(solve(board, 0, 0))
print(board)
