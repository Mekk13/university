"""
max subarray sum
"""
### dynamic loca not even recursive????

def max_sum(arr:list):
    max_here=arr[0]
    maxi=arr[0]
    for nr in arr[1:]:
        max_here=max(nr,max_here+nr)
        maxi=max(maxi,max_here)
    return maxi

print(max_sum([-2,-5,6,-2,-3,1,5,-6]))

