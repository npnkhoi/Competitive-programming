# Read input
hotdogs = list(map(int, input().split()))
buns = list(map(int, input().split()))

# Seperate size and items
num_hotdogs = hotdogs[0]
hotdogs = hotdogs[1:]

num_buns = buns[0]
buns = buns[1:]

# Dynammic programming
MAX_WEIGHT = 10**5
INF = 1000

def dp(items):
    result = [INF] * (MAX_WEIGHT + 1)
    result[0] = 0
    
    for item in items:
        for weight in range(MAX_WEIGHT - item, -1, -1):
            if result[weight] == INF:
                continue
            new_weight = weight + item
            result[new_weight] = min(result[new_weight], result[weight] + 1)
    return result

min_hotdogs = dp(hotdogs)
min_buns = dp(buns)
    
# Find the answer
answer = INF
for value in range(1, MAX_WEIGHT + 1):
    if min_hotdogs[value] != INF and min_buns[value] != INF:
        answer = min(answer, min_hotdogs[value] + min_buns[value])
if answer == INF:
    print('impossible')
else:
    print(answer)