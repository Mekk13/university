
def coin(coins:list,money):
    v=[float('inf')]*(money+1)
    v[0]=0
    for i in range(1,money+1):
        mini=v[i-coins[0]]+1
        for coin in coins:
            if i-coin>=0:
                mini=min(v[i-coin]+1,mini)
        v[i]=mini
    return v[money]

print(coin([1,2,5,10],13))
