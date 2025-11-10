def merge_sort(array)-> list:
    if len(array) <= 1:
        return array
    m=len(array)//2
    list1=merge_sort(array[:m]) #slicing the array in 2
    list2=merge_sort(array[m:])
    return merge(list1,list2)

def binary_search(array, left:int, right:int, n:int):
    mid=(left+right)//2
    if(n==array[mid]):
        return mid
    if n>array[mid]:
        binary_search(array, mid+1, right, n)
    elif n<array[mid]:
        binary_search(array, left, mid-1, n)


def merge(list1,list2,result_list) -> list:
    output=[]
    idxi=0
    idxj=0
    while idxi<len(list1) and idxj<len(list2):
        if list1[idxi]<list2[idxj]:
            output.append(list1[idxi])
            idxi+=1
        else:
            output.append(list2[idxj])
            idxj+=1
    while idxi<len(list1):
        output.append(list1[idxi])
        idxi+=1
    while idxj<len(list2):
        output.append(list2[idxj])
        idxj+=1
    return output

###############        BACKTRACKING

##Generate the permutations hehehehe

def consistent(x):
    return len(set(x))==len(x) #converts to a set where elem dont repeat and checks if the len is the same for the array

def solution(x,n):
    return len(x)==n

def solution_found(x)
    print("solution: ",x)


def back_rec(x,n):
    x.append(0)
    for i in range(0,n):
        x[len(x)-1]=i
        if consistent(x):
        if solution(x,n):
            solution_found(x)
        else:
            back_rec(x[:],n)































