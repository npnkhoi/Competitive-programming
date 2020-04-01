x = int(input())
res = 1000 * (x // 500);
x = x % 500;
x -= x % 5
res += x
print(res) 