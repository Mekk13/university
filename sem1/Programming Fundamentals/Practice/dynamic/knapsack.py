from texttable import Texttable
W=10
weights=[5,3,10,4,2]
values=[2,3,4,3,6]

def pretty_print(v:list):
    t=Texttable()
    t.header(['X']+list(range(W+1)))
    for i in range(len(v)):
        t.add_row([i]+v[i])
    print(t.draw())

def knapsack(W:int,values,weights:list):
    V=[[0 for i in range(W+1)] for j in range(len(values)+1)]

    for i in range(len(values)+1):
        for j in range(W+1):
            if i==0 or j==0:
                V[i][j]=0
            elif weights[i-1]>j:
                V[i][j]=V[i-1][j]
            else:
                V[i][j]=max(V[i-1][j],values[i-1]+V[i-1][j-weights[i-1]])
    pretty_print(V)
    return V[len(values)][W]

print(knapsack(W,values,weights))