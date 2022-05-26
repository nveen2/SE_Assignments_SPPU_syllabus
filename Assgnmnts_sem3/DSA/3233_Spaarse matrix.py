def maToSparse(mat, r , c):
    ans = []
    for i in range(0,r):
        for j in range(0,c):
            if(mat[i][j] != 0):
                ans.append((i,j,mat[i][j]))
    transpose = []
    for j in range(0,c):
        for i in range(0,r):
            if(mat[i][j] != 0):
                transpose.append((j,i,mat[i][j]))
    return ans,transpose

def fasTranspose(mat,r ,c):
    count = []          #freq
    indices = []        #starting index of each col.
    transpose = []
    for i in range(0,c):
        count.append(0)
        indices.append(0)

    for i in mat:
        r_,c_,v_ = i
        count[c_] += 1
        transpose.append((0,0,0))

    #starting pos of ith col = starting pos of (i-1)th col + elements in (i-1)th col
    
    for i in range (1,c):
        indices[i] = count[i-1] + indices[i-1]

    for i in mat:
        r_,c_,v_ = i
        transpose[indices[c_]] = (c_,r_,v_)
        indices[c_] += 1

    return transpose

def add_(lis1, lis2):
    ptr1 = 0
    ptr2 = 0
    result = []
    while(ptr1 < len(lis1) and ptr2 < len(lis2)):
        r1,c1,v1 = lis1[ptr1]
        r2,c2,v2 = lis2[ptr2]
        if(r1 < r2):
            result.append(lis1[ptr1])
            ptr1 += 1
        elif(r1 == r2):
            if(c1 < c2):
                result.append(lis1[ptr1])
                ptr1 += 1
            elif(c1 == c2):
                result.append((r1,c1,v1+v2))
                ptr1 += 1
                ptr2 += 1
            else:
                result.append(lis2[ptr2])
                ptr2 += 1
        else:
            result.append(lis2[ptr2])
            ptr2 += 1
    
    while(ptr1 < len(lis1)):
        result.append(lis1[ptr1])
        ptr1 += 1
        
    while(ptr2 < len(lis2)):
        result.append(lis2[ptr2])
        ptr2 += 1

    return result

def printt(sp):
    for i in sp:
        a,b,c = i
        print(a, ' ', b, ' ', c)

mat = []
str = input('Rows and Columns of Matrix : ')
r, c = (int(x) for x in str.split())

for  i in range(0,r):
    lis = list(map(int,input().split()))
    mat.append(lis)
    
sp,transposeSp = maToSparse(mat,r,c)
fastT = fasTranspose(sp,r,c)

result = add_(sp,fastT)

print('Sparse Matrix : ')
printt(sp)

print('Normal Transpose')
printt(transposeSp)

print('Fast Transpose : ')
printt(fastT)

print('Sum : ')
printt(result)