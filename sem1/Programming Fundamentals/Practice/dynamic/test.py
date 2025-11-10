from random import randint
"""
class Fib:
    def __init__(self,nr,a=0):
        self.nr = nr
        self.a = a
    def __add__(self,value):
        if isinstance(value, int):  # Ensure it's a number
            return Fib(self.nr, self.a + value)  # Create a new Fib object with updated 'a'
        return NotImplemented
    def __str__(self):
        if self.nr<=1:
            return self.nr
        m=[0 for i in range(self.nr*self.nr)]
        m[1]=1
        for i in range(2,self.nr*self.nr):
            m[i]=m[i-1]+m[i-2]
        ma=[[0 for i in range(self.nr)] for j in range(self.nr)]
        s=0
        for i in range(self.nr):
            for j in range(self.nr):
                ma[i][j]=m[s]+self.a
                s+=1
        return '\n'.join([' '.join(map(str, row)) for row in ma])

fm=Fib(2)
fm2=fm+10
print(fm2)
"""

r=randint(0,100)
print(r)