def merge(lis1, lis2):
    ans = []
    n = len(lis1)
    m = len(lis2)
    ptr1 = 0
    ptr2 = 0
    while(ptr1 < n and ptr2 < m):
        prn1,date1,month1 = lis1[ptr1]
        prn2,date2,month2 = lis2[ptr2]

        if(month1 < month2):
            ans.append((prn1,date1,month1))
            ptr1 += 1
        elif(month1 > month2):
            ans.append((prn2,date2,month2))
            ptr2 += 1
        else:
            if(date1 < date2):
                ans.append((prn1,date1,month1))
                ptr1 += 1
            else:
                ans.append((prn2,date2,month2))
                ptr2 += 1
    
    while(ptr1 < n):
        ans.append(lis1[ptr1])
        ptr1 += 1

    while(ptr2 < m):
        ans.append(lis2[ptr2])
        ptr2 += 1
            
    return ans


n = int(input('Enter size of List A : '))
lis1 = []
lis2 = []

#capthe = {(1,3,5,7,8,10,12):31,(2,):28,(4,6,9,11):30}
for i in range(0,n):
    str = input('')
    prn,date,month = (int(x) for x in str.split())
    lis1.append((prn,date,month))
    #for i in capthe.keys():
    #    if(mon in i and date<=capthe[i]):
    #        DivA.append(tuple(stu))
    #        break
    
m = int(input('Enter size of List B : '))
for i in range (0,m):
    str = input('')
    prn,date,month  = (int(x) for x in str.split())
    lis2.append((prn,date,month))
    #for i in capthe.keys():
    #    if(mon in i and date<=capthe[i]):
    #        DivA.append(tuple(stu))
    #        break

ans = merge(lis1,lis2)
for x in ans:
    print(x)
