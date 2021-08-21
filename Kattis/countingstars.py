case = 0
while True:
  # Read input
  line = input()
  print(f'line = {line}', type(line))
  if line.strip() == "":
    break
  
  print(str(line).split())
  height, width = map(int, str(line).split())
  map = []
  # vis = []
  for i in range(height):
    map.append(input())
    # vis.append([False for _ in range(width)])
  
  # def dfs(row: int, col: int) -> None:
  #   vis[row][col] = True
  #   for nei_row in range(row-1, row+2):
  #     for nei_col in range(col-1, col+2):

  #       if nei_row == row and nei_col == col:
  #         continue
  #       if nei_row < 0 or nei_row >= height or nei_col < 0 or nei_col >= width:
  #         continue
  #       if not vis[nei_row][nei_col]:
  #         dfs(nei_row, nei_col)
      

  # # Process
  # result = 0
  # for row in range(height):
  #   for col in range(width):
  #     if map[row][col] == '-' and not vis[row][col]:
  #       dfs(row, col)
  #       result += 1
  
  # case += 1
  # print(f'Case {case}: {result}')
