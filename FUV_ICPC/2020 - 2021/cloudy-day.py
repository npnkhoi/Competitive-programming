# Input
n = int(input()) # cities
population = list(map(int, input().split()))
x = list(map(int, input().split()))
m = int(input()) # clouds
y = list(map(int, input().split()))
r = list(map(int, input().split()))

# Put all points to one list -> sort
points = []
# One city -> One point (type 0)
for i in range(n):
    points.append((x[i], 0, i))
# One cloud -> 2 points for head and tail (type -1 and +1)
for i in range(m):
    points.append((y[i] - r[i], -1, i))
    points.append((y[i] + r[i], +1, i))
# When sorting, if some points have the same coordinate, 
# Python will prioritize the type
points.sort()

# Iterate through the point list => calculate
# 1. Number of uncovered citizens
# 2. For each cloud, number of citizens covered by only that cloud
current_clouds = set()
result = 0
can_free = [0] * m
for point in points:
    id = point[2]
    if point[1] == 0: # This is a city
        id = point[2]
        if len(current_clouds) == 0:
            result += population[id]
        if len(current_clouds) == 1:
            can_free[next(iter(current_clouds))] += population[id]
    elif point[1] == -1:
        current_clouds.add(id)
    else:
        current_clouds.discard(id)

# Output
result += max(can_free)
print(result)