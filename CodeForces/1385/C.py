num_tests = int(input())

for _ in range(num_tests):
    n = int(input())
    a = list(map(int, input().split())) # a = [3 5 6 4]

    pointer = n - 1
    while pointer > 0 and a[pointer - 1] >= a[pointer]:
        pointer -= 1
    while pointer > 0 and a[pointer - 1] <= a[pointer]:
        pointer -= 1
    print(pointer)
    

