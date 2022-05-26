def checkUpperTraingle(lis, r, c):
    for i in range(0,r):
        for j in range(0,i):
            if(lis[i][j] != 0):
                return False
    return True

def diagSum(lis, r ,c):
    if(r != c):
        return -1
    sum = 0
    for i in range (0,r):
        sum += lis[i][i]
    return sum

def transpose(lis, r , c):
    ans = []
    for i in range (0, c):
        temp = []
        for j in range (0,r):
            temp.append(lis[j][i])
        ans.append(temp)
    return ans

def saddlePoints(lis, r , c):
    row = []
    col = []
    ans = []
    for i in range (0,r):
        mn = lis[i][0]
        for j in lis[i]:
            mn = min(mn, j)
        for j in range(0,c):
            if(lis[i][j] == mn):            #tackled multiple same mn values
                row.append((mn,i,j))

    for i in range (0,c):                   #i reps col
        mx = lis[0][i]
        for j in range (1,r):               #j reps row
            mx = max(mx, lis[j][i])
        for j in range(0,r):        
            if(lis[j][i] == mx):            #tackled multiple same mx values
                col.append((mx,j,i))        #format val,row,col

    for i in row:
        if i in col:
            ans.append(i)
    return ans

def product(lis1, r1,c1, lis2, r2,c2):
    
    if(c1 != r2):
        return False,-1
    ans = []
    for i in range(0,r1):
        a = []
        ans.append(a)
        val = 0
        for j in range(0,c1):
            val += (lis1[j][i] * lis2[i][j])
        ans[i]
    return True,ans
    

str = input('Enter the Dimensions of Matrix 1 : ')
r1, c1 = (int(x) for x in str.split())

mat1 = []

print('Enter the Elements of Matrix 1 : ')
for i in range (0,r1):
    str_ = input()
    mat1.append(list(map(int, str_.split())))

str2 = input('Enter the Dimensions of Matrix 1 : ')
r2, c2 = (int(x) for x in str.split())

mat2 = []

print('Enter the Elements of Matrix 2 : ')
for i in range (0,r2):
    str_ = input()
    mat2.append(list(map(int, str_.split())))

print(checkUpperTraingle(mat1, r1, c1))
print(diagSum(mat1,r1,c1))
print(transpose(mat1,r1,c1))
print(saddlePoints(mat1,r1,c1)) 
print(product(mat1,r1,c1,mat2,r2,c2))
