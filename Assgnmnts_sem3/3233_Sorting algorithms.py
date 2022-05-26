def bubbly_sort(ls,n):
    arr = ls.copy()
    print(arr)
    for i in range(n-1):
        flag = True
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                flag = False
                arr[j],arr[j+1] = arr[j+1],arr[j]
        print(arr)
        if flag: break

def selection_sort(ls,n):
    arr = ls.copy()
    print(arr)
    for i in range(n-1):
        min = i
        for j in range(i+1,n):
            if arr[j] < arr[min]:
                min = j
        arr[i],arr[min]=arr[min],arr[i]
        print(arr)

def insertion_sort(ls,n):
    arr = ls.copy()
    print(arr)
    i = 1
    while(i<n):
        current = arr[i]
        j = i-1
        while j>=0 and arr[j]>current:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = current
        i += 1
        print(arr)

def shell_short(ls,n):
    arr = ls.copy()
    gap = n//2

    print(arr)
    while gap>0:
        for i in range(gap,n):
            current = arr[i]
            j = i - gap
            while j>=0 and arr[j]> current:
                arr[j+gap] = arr[j]
                j -= gap
            arr[j+gap] = current
        gap //= 2
        print(arr)

n = int(input("Size of the Array/list: "))
ls = list(map(int,input("Enter the percentage of student seperated by space: ").split()))
print('Bubbly Sort')
bubbly_sort(ls,n)
print('Selection Sort')
selection_sort(ls,n)
print('Insertion Sort')
insertion_sort(ls,n)
print('Shell Sort')
shell_short(ls,n)
