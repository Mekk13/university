
def mss(arr:list):
    start=0
    stop=-10
    maxi=arr[0]
    dp=[0]*(len(arr))
    dp[0]=arr[0]
    for i in range(1,len(arr)):
        if max(arr[i],dp[i-1]+arr[i])==arr[i]:
            start=i
        dp[i]=max(arr[i],dp[i-1]+arr[i])
        if dp[i]>maxi:
            maxi=dp[i]
            stop=i
    for i in range(start,stop+1):
        print(arr[i])
    return start,stop,maxi

s,t,m=mss([2,-3,10,1,-2,-4,12,-2])