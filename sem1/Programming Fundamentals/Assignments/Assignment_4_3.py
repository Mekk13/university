"""
Given the set of positive integers S and the natural number k, display one
of the subsets of S which sum to k. For example, if S = { 2, 3, 5, 7, 8 } and k = 14, subset { 2, 5, 7 } sums to 14.




"""

def subset(array,matrix,n,sum):
    if sum==0 :
        return True
    if n==0:
        return False
    if matrix[n][sum]!=-1:
        return matrix[n][sum]
    if array[n-1]>sum:
        matrix[n][sum] = subset(array,matrix,n-1,sum)
    else:
        matrix[n][sum]=subset(array,matrix,n-1,sum) or subset(array,matrix,n-1,sum-array[n-1])

    return matrix[n][sum]

def main():
    array=list(map(int, input("Enter integers separated by space: ").split()))
    sum=int(input("Enter the sum number: "))
    n=len(array)
    matrix=[[-1 for i in range(n+1)]for j in range(sum+1)]

main()

