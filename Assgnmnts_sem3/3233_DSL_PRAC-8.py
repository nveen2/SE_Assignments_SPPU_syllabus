def bucket_sort(ls,n,r):
    arr = []
    print(ls)

    bucket = [0]*(r+1)

    for i in range(0,n):
        bucket[ls[i]] += 1

    for i in range(0,r+1):
        for j in range(0,bucket[i]):
            arr.append(i)
        
    print(arr)

def radix_bucket_sort(ls,n):
    arr = ls.copy()

    len = 10
    digit = 1
    max_num = max(ls)

    while max_num>=digit:
        bucket = [[] for i in range(len)]
        for i in range(0,n):
            current = (arr[i]//digit)%len
            bucket[current].append(arr[i])
        digit*=len

        a = 0
        for i in range(0,len):
            for x in bucket[i]:
                arr[a] = x
                a+=1
        print(bucket)

def counting_sort(ls,n,r):
    count = [0]*(r+1)

    for i in ls:
        count[i] += 1

    pos = [0]*(r+1)

    for i in range(r):
        pos[i+1] = pos[i]+count[i]

    temp = [0]*n
    for i in ls:
        temp[pos[i]] = i
        pos[i] += 1
    
    print(temp)

def modified_counting_sort(ls,digit):
    count = [0]*(10)
    new_ls =[0]*(len(ls)) 

    for i in ls:
        current = (i//digit)%10
        count[current] += 1

    pos = [0]*(10)

    for i in range(9):
        pos[i+1] = pos[i]+count[i]

    for i in range(len(ls)):
        current = (ls[i]//digit)%10
        new_ls[pos[current]] = ls[i]
        pos[current] += 1

    for i in range(len(ls)):
        ls[i] = new_ls[i]

def radix_count_sort(ls):
    arr = ls.copy()

    digit = 1
    max_num = max(ls)

    while max_num>=digit:
        modified_counting_sort(arr,digit)
        digit *= 10
        print(arr)    

def quick_sort(ls,l,r):
    if l<r:
        pivot = ls[l]
        i = l+1
        j = r
        while i<=j:
            while i <len(ls) and ls[i]<=pivot:
                i+=1
            while ls[j]>pivot:
                j-=1
            if i<j:
                ls[i],ls[j] = ls[j],ls[i]
        
        ls[j],ls[l] = ls[l],ls[j]
        
        quick_sort(ls,l,j-1)
        quick_sort(ls,j+1,r)
