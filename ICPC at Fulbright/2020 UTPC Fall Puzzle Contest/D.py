import math
a = int(input())
num = math.ceil(math.sqrt(2*a-1))
if num%2 == 0:
    print(num+1)
else:
    if a == 3:
        print (5)
    else:
        print(num)