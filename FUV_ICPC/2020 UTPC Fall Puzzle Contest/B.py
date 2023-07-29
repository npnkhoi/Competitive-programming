def writer(a,b,l):
    string = ""
    for i in range (l):
        cur = a[i]
        for j in range (l):
            if cur == b[j]:
                string += str(j+1)
                break
    print(string)
n = int(input())
a = input()
b = input()
writer(a,b,n)