n = int(input())
a = list(map(int, input().split()))

# Find the largest unique value in a[]
unique = -1

for value in range(6, 0, -1): # 6 -> 1
    if a.count(value) == 1: # find number of occurences of value
        unique = value
        break

if unique == -1:
    print('none')
else:
    # Find the position of the unique value
    for i in range(n):
        if a[i] == unique:
            print(i + 1)
            break