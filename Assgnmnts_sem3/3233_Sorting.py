N=int(input("Enter total no.of students: "))
pctg_array=[]
for i in range(N):
    pctg=int(input("Enter percentage of student: "))
    pctg_array.append(pctg)


#Selection sort algorithm
def selection_sort():
    for i in range( N - 1 ): 
        min = i

        for j in range( i + 1, N ):
            if pctg_array[j] < pctg_array[min] :
                min = j

        if min != i :
            temp = pctg_array[i]
            pctg_array[i] = pctg_array[min]
            pctg_array[min] = temp
            print(pctg_array)

    
    
#Bubble sort algorithm
def bubble_sort():
    for i in range(N-1):
        for j in range(0, N-i-1):
            if pctg_array[j] >pctg_array[j + 1] :
                pctg_array[j], pctg_array[j + 1] = pctg_array[j + 1], pctg_array[j]
                print(pctg_array)

    

#Insertion sort algorithm
def insertion_sort():
    for i in range(1, N):
        key = pctg_array[i]
        j = i-1
        while j >=0 and key < pctg_array[j] :
                pctg_array[j+1] = pctg_array[j]
                j -= 1
        pctg_array[j+1] = key
        print(pctg_array)

   



#Shell sort algorithm
def shell_sort():
    gap = N//2
    while gap > 0:
          for i in range(gap,N):
            temp = pctg_array[i]
            j = i
            while  j >= gap and pctg_array[j-gap] >temp:
                pctg_array[j] = pctg_array[j-gap]
                j -= gap
            pctg_array[j] = temp
          gap //= 2
          print(pctg_array)


#Drive code
flag=1
print("1.Selection Sort")
print("2.Bubble Sort")
print("3.Insertion Sort")
print("4.Shell Sort")
while(flag==1):
    k=int(input("Enter your choice 1/2/3/4: "))
    
    if k==1:
        print("Unsorted array: ",pctg_array)
        selection_sort()
        flag=0
    elif k==2:
        print("Unsorted array: ",pctg_array)
        bubble_sort()
        flag=0
    elif k==3:
        print("Unsorted array: ",pctg_array)
        insertion_sort()
        flag=0
    elif k==4:
        print("Unsorted array: ",pctg_array)
        shell_sort()
        flag=0
    else:
        print("Please check your input!!")
        flag=1


   


  
    
           
           
            
  
