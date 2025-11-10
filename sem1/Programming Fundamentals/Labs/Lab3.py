# given an array of dist elem, find all the idk
#T(n^3)
def merge(array):
    if len(array) <=1:
        return array
    m=len(array)//2
    l1=merge(array[:m])
    l2=merge(array[m:])
    return merge_lists(l1,l2)

def merge_lists(l1,l2)->[]:
    output=[]
    j=0
    i=0
    while(i<len(l1) and j<len(l2)):
        if l1[i]<l2[j]:
            output.append(l1[i])
            i+=1
        else:
            output.append(l2[j])
            j+=1
    while i<len(l1):
        output.append(l1[i])
        i+=1
    while j<len(l2):
        output.append(l2[j])
        j+=1
    return output

def brut_3_sum(array: list, sum_e:int)->[]:
    output=[]
    for i in range(len(array)-2):
        for j in range(i+1, len(array)-1):
            for k in range(j+1, len(array)):
                if array[i]+array[j]+array[k] ==sum_e:
                    output.append((array[i],array[j],array[k]))
    return output
def main():
    pass