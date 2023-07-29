M,N,E = map(int,input().split())

def product(list_of):
    numb = 1
    for l in list_of:
        numb *= l
    return numb

right_side = list(map(int,input().split()))
left_side_chosen = [False for _ in range (M)]
right_side_connection = [ [] for _ in range (N)]

list_of_prime = [True for _ in range (max(right_side))]
list_of_prime[0],list_of_prime[1] = None,None
len_list = len(list_of_prime)
for i in range (2,len_list):
    if list_of_prime[i]:
        for j in range  (i*i,len_list,i):
            list_of_prime[j] = False


for im in range (E):
    start,des,weight = map(int,input().split())
    right_side_connection[des-1].append(start)
     
num = product(right_side)
for each in range (2,len(list_of_prime)):
    if list_of_prime[each]:
        if num%each == 0:
            print(each, end = ' ')
            num/=each



    
    
    
    