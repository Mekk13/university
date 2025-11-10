
def LIS(arr:list):
    max_len=1
    best_end=0

    indices=[1]
    previous=[-1]
    for i in range(1,len(arr)):
        indices.append(1)
        previous.append(-1)
        for j in range(i-1,-1,-1):
            if (indices[j]+1>indices[i]) and arr[j]<arr[i]:
                indices[i]=indices[j]+1
                previous[i]=j

        if indices[i]>max_len:
            max_len=indices[i]
            best_end=i

    ###build solution:
    A=[arr[best_end]]
    while previous[best_end]!=-1:
        A.append(arr[previous[best_end]])
        best_end=previous[best_end]
    A.reverse()
    print(f"Max Length: {max_len}\nSubarray: {A}")


LIS([0,4,12,2,10,6,9,13,3,11,7,15])