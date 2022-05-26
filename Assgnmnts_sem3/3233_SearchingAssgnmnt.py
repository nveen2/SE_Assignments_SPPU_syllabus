def linearSearch(lst, k):
    for i in range(len(lst)):
        if(k==lst[i]):
            return f"Roll number {k} attended the program."
    return f"{k} not present in program ;p."

def sentinalSearch(lst, k):
    lst.append(k)
    i = 0
    while(lst[i]!=k):
        i += 1
    lst.pop()
    return f"{k} not present in program ;p." if(i == len(lst)) else f"Roll number {k} attended the program."

def binSearch(lst, k):
    s = 0
    e = len(lst)-1
    itr = 0;
    while(s<=e):
        mid = (s+e)//2
        if(lst[mid]==k):
            itr += 1;
            return f"Roll number {k} attended the program. {itr} iterations"
        elif(lst[mid]<k):
            itr += 1;
            s = mid+1
        else:
            itr += 1;
            e = mid-1
    return f"{k} not present in program ;p. {itr} iterations"

def ReccBinSearch(lst, k, s, e):
    if(s>e):
        return f"{k} not present in program ;p."
    mid = (s+e)//2
    if(lst[mid]==k):
        return f"Roll number {k} attended the program."
    elif(lst[mid]<k):
        return ReccBinSearch(lst, k, mid+1, e)
    else:
        return ReccBinSearch(lst, k, s, mid-1)

def fibonacciSearch(lst, k):
    n = len(lst)
    fibM2 = 0  
    fibM1 = 1  
    fibM = fibM2 + fibM1  
    while (fibM < n):
        fibM2 = fibM1
        fibM1 = fibM
        fibM = fibM2 + fibM1
 
    offset = -1
    itr = 0;
    while (fibM > 1):
        i = offset+fibM2 if(offset+fibM2 < n-1) else n-1
        if (lst[i] == k):
            itr += 1;
            return f"Roll number {k} attended the program. {itr} iterations"
        elif (lst[i] < k):
            itr += 1;
            fibM = fibM1
            fibM1 = fibM2
            fibM2 = fibM - fibM1
            offset = i
        else:
            itr += 1;
            fibM = fibM2
            fibM1 = fibM1 - fibM2
            fibM2 = fibM - fibM1
 
    if(fibM1 and lst[n-1] == k):
        itr += 1;
        return f"Roll number {k} attended the program. {itr} iterations"
 
    return f"{k} not present in program ;p. {itr} iterations"

#def userCases():
    # INPUT
    # n = int(input("Enter the number of students\n> "))
    # lst = []
    # for i in range(n):
    #     inp = int(input("Enter the roll number of student: "))
    #     lst.append(inp)
    # k = int(input("Enter the roll number to search in list\n> "))

    # print()
    # print("Result by Linear Search...")
    # print(linearSearch(lst, k))
    # print()
    # print("Result by Sentinal Search...")
    # print(sentinalSearch(lst, k))
    # print()

    # n = int(input("Enter the number of students\n> "))
    # lst = []
    # for i in range(n):
    #     inp = int(input("Enter the roll number of student(in sorted order): "))
    #     lst.append(inp)
    # k = int(input("Enter the roll number to search in list\n> "))
    # print("Result by Binary Search...")
    # print(binSearch(lst, k))
    # print()
    # print("Result by Reccursive Binary Search...")
    # print(ReccBinSearch(lst, k, 0, len(lst)-1))
    # print()
    # print("Result by Fibonacci Search...")
    # print(fibonacciSearch(lst, k))

    # Sample Case

def customCase():
    a = [1,2,3,4,5,7,9]
    k = 10
    print("List of student's rollnumber is",a)
    print()
    print("Result by Linear Search...")
    print(linearSearch(a, k))
    print()
    print("Result by Sentinal Search...")
    print(sentinalSearch(a, k))
    print()
    print("Result by Binary Search...")
    print(binSearch(a, k))
    print()
    print("Result by Reccursive Binary Search...")
    print(ReccBinSearch(a, k, 0, len(a)-1))
    print()
    print("Result by Fibonacci Search...")
    print(fibonacciSearch(a, k))

customCase()