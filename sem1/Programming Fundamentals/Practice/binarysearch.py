def binary(arr,x,l,r):
    if l<=r:
        mid=(l+r)//2
        if arr[mid]==x:
            return mid
        elif arr[mid]>x:
            return binary(arr,x,l,mid-1)
        else:
            return binary(arr,x,mid+1,r)
    else:
        return -1

array=[1,2,3,4,5,6,7,8,9,10,45,66,69,77,88,99,100,101,103,104,200,230,420,450,451]
print(binary(array,1,0,len(array)-1))