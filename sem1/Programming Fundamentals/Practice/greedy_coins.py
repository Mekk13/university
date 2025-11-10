"""
the coin problem.
"""

def current_sum(b:list,sum_total:int):
    amount=0
    for coin in b:
        nr_coins=(sum_total-amount)//coin
        if nr_coins==0:
            nr_coins=1
        amount+=coin*nr_coins
    return amount

def select_most_promising(c:list):
    return max(c)

def acceptable(b:list,sum_total:int):
    if current_sum(b,sum_total)<=sum_total:
        return True
    return False

def solution(b:list,sum_total:int):
    if current_sum(b,sum_total)==sum_total:
        return True
    return False

def pretty_print(b:list,sum_total:int):
    sol=''
    amount=0
    for coin in b:
        nr_coins=(sum_total-amount)//coin
        amount+=coin*nr_coins
        sol+=str(nr_coins)+'*'+str(coin)
        if sum_total-amount>0:
            sol+=' + '
    return sol

def greedy(c:list,sum_total:int):
    b=[]
    while not solution(b,sum_total) and c!=[]:
        candidate=select_most_promising(c)
        c.remove(candidate)
        if acceptable(b+[candidate],sum_total):
            b.append(candidate)
    if solution(b,sum_total):
        return pretty_print(b,sum_total)

for money in range(1,55):
    print("Amount: " + str(money)+"="+greedy([1,5,10],money))