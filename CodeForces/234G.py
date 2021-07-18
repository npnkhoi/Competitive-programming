import math

with open('input.txt', 'r') as inp:
  with open('output.txt', '+w') as out:
    n = int(inp.readline())


    n_match = int(math.log2(n - 1) + 1)
    out.write(str(n_match) + '\n')

    for column in range(n_match):
      # At one round
      team_1 = []
      for i in range(n):
        if i // (2 ** column) % 2 == 0:
          team_1.append(i)
      out.write(str(len(team_1)) + ' ')
      for player in team_1:
        out.write(str(player + 1) + ' ')
      out.write('\n')

