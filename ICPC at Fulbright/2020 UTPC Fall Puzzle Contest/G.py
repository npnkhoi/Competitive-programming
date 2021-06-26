def max_sigma(l,r):
    num_digit = len(str(r))
    nine = 0
    for i in range(num_digit):
        nine = 10*nine + 9
        
    half = int((nine+1)/2)
    if (nine/2 >= l) and (nine/2 <= r):
        
        return half*(nine - half)
    
    if half > r:
        return r*(nine - r)
    return l*(nine - l)

n = int(input())
for _ in range(n):
    lr = input().split()
    left = int(lr[0])
    right = int(lr[1])
    print(max_sigma(left,right))
    
