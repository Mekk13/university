class PrimeList:
    def __init__(self):
        self.primes = []
        self.last=1

    def is_prime(self, num):
        if num<2:
            return False
        if num==2:
            return True
        for i in range(2,(num//2)+1):
            if num%i==0:
                return False
        return True

    def generate_primes(self,until):
        while len(self.primes)<=until:
            self.last+=1
            if self.is_prime(self.last):
                self.primes.append(self.last)

    def __getitem__(self,index):
        if index<0:
            raise IndexError("index cant be negative")
        if len(self.primes)<=index:
            self.generate_primes(index)
        return self.primes[index]

    def __setitem__(self,index,value):
        raise PrimeException("List is read only")


class PrimeException(Exception):
    pass

data=PrimeList()
for i in range(10):
    print(data[i])
print(data[100])

try:
    data[5]=10
except PrimeException as e:
    print(e)