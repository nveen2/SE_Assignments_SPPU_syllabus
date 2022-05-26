array=[1,12,14,16,19,26,58,71,80,95]
l=len(array)


def simple(mat,n,key):
    count=0
    for i in range(n):
        count+=1
        if mat[i]==key:
            print("Number",key,"is at index: ",i)
            break
    else:
        print("Not Found!")
    print("Number of comparison: ",count)
        
def sentinel(mat,n,key):
    mat.append(key)
    i=0
    while(mat[i]!=key):
        i+=1
    if i<n:
        count+=1
        print("Number",key,"is at index: ",i)
    else:
        count+=1
        print("Not Found!")
    print("Number of comparison: ",i)

def binary(mat,n,key):
    beg=0
    last=n-1
    count=0
    while(beg<=last):
        count+=1
        mid=int((beg+last)/2)
        if mat[mid]==key:
            print("Number",key,"is at index: ",mid)
            break
        elif mat[mid]>key:
            last=mid-1
        else:
            beg=mid+1
    else:
        print("Not Found!")
    print("Number of comparison: ",count)

def fibonacci(mat,n,key):
    x=0
    y=1
    count=0
    while(y<n):
        z=x+y
        x=y
        y=z
    fabm=y
    fabm1=x
    fabm2=y-x
    offset=0
    while(fabm>1):
        count+=1
        i=min(fabm2+offset,n-1)
        if mat[i]<key:
            fabm=fabm1
            fabm1=fabm2
            fabm2=fabm-fabm1
            offset=i
        elif mat[i]>key:
            fabm=fabm2
            fabm1=fabm1-fabm2
            fabm2=fabm-fabm1
        elif mat[i]==key:
            print("Number of comparison: ",count)
            return i
    


a=int(input("Enter number to be searched: "))
flag=1
print("1.Simple Search")
print("2.Sentinel Search")
print("3.Binary Search")
print("4.fabonacci Search")
while(flag==1):
    k=int(input("Enter way to search for number:"))
    
    if k==1:
        simple(array,l,a)
        flag=0
    elif k==2:
        sentinel(array,l,a)
        flag=0
    elif k==3:
        binary(array,l,a)
        flag=0
    elif k==4:
        h=fibonacci(array,10,a)
        print("Number",a,"is at index: ",h)
        flag=0
    else:
        print("wrong choice!")
        flag=1

