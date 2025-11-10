
def consistent(k):
    for i in range(k):
        if x[i]==x[k]:
            return False
    return True

def valid(n,k):
    if k!=n:
        return False
    return True

def foundsol():
    print(x)
    s.append(x)
    return

def back(k,n):
    if valid(n, k):
        foundsol()
        return
    for i in range (n):
        x[k]=i
        if consistent(k):
            back(k+1,n)

n=int(input("n: "))
x=[None]*n
s=[]
back(0,n)