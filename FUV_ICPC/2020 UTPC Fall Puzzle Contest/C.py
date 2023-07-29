def trans(numb):
    return sum(list(map(int,bin(numb)[2:])))
def sumer(numb):
    return numb*(numb+1)//2
n = int(input())
list_of = list(map(int,input().split()))
dict_of = {}
for i in range (n):
    num = trans(list_of[i])
    try:
        dict_of[num] += 1
    except:
        dict_of[num] = 1
sumeru = 0
for j in dict_of:
    sumeru += sumer(dict_of[j]-1)
print(sumeru)
    