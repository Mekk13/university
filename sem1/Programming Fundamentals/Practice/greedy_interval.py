"""
interval scheduling problem
"""

def select_best_candidate(c:list):
    """
    returns minimum by end time
    """
    return min(c, key=lambda x: x[1])

def acceptable(b:list):
    """
    checking if the events overlap
    """
    for i in range(len(b)-1):
        if b[i][1]>b[i+1][0]:
            return False
    return True

def pretty_print(b:list):
    lst=''
    for i in range(len(b)):
        lst+=str(i+1)+") "+"Starts: "+str(b[i][0])+" Ends: "+str(b[i][1])
        lst+='\n'
    return lst

def greedy(c:list):
    b=[]
    while c!=[]:
        candidate=select_best_candidate(c)
        c.remove(candidate)
        if acceptable(b+[candidate]):
            b.append(candidate)
    return pretty_print(b)

events=[(1,2),(3,4),(2,5),(1,6),(2,7),(3,5),(4,6),(4,5),(5,8)]
print(greedy(events))