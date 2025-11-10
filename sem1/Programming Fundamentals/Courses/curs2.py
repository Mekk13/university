def fact(n : int)-> int:
    if(n==0):
        return 1
    return n*fact(n-1)

#key 0 has associated value 1
#key 1 has associated value 1
cache={0:1, 1:1}

"""
def fib(n: int) -> int:
    if n<2:
        return 1
    return fib(n-2)+fib(n-1)
"""

def fib(n: int) -> int:
    if n in cache:
        return cache[n]
    cache[n]=fib(n-1)+fib(n-2)
    return cache[n]

for i in range(10):
    print(i, fib(i))
