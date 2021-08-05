n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

def min_diff(a, b, n, m):
    j = 0
    result = 10**9

    for i in range(n):
        while j + 1 < m and b[j] < a[i]:
            j += 1
        result = min(result, abs(a[i] - b[j]))
    
    # print(result)
    return result

a.sort()
b.sort()

print(min(min_diff(a, b, n, m), min_diff(b, a, m, n)))