class Product:
    def __init__(self,name,type,price):
        self.name=name
        self.type=type
        self.price=price

    @property
    def get_name(self):
        return self.name

    @property
    def get_price(self):
        return self.price

    def __str__(self):
        return f"Name: {self.name} Type: {self.type} Price: {self.price}"

def bubble(arr):
    for n in range(len(arr)-1,0,-1):
        swapped = False
        for i in range(n):
            if arr[i].get_name>arr[i+1].get_name:
                arr[i],arr[i+1]=arr[i+1],arr[i]
                swapped=True
            elif arr[i].get_name==arr[i+1].get_name:
                if arr[i].get_price<=arr[i+1].get_price:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
                    swapped=True
        if not swapped:
            break

def merge(arr,l,m,r):
    n1=m-l+1
    n2=r-m
    L=[]
    R=[]
    for i in range(n1):
        L.append(arr[i+l])
    for j in range(n2):
        R.append(arr[m+j+1])
    i=0
    j=0
    k=l
    while i<n1 and j<n2:
        if L[i].get_name<R[j].get_name:
            arr[k]=L[i]
            i+=1
        elif L[i].get_name==R[j].get_name:
            if L[i].get_price>=R[j].get_price:
                arr[k]=L[i]
                i+=1
            else:
                arr[k]=R[j]
                j+=1
        else:
            arr[k]=R[j]
            j+=1
        k+=1

    while i<n1:
        arr[k]=L[i]
        k+=1
        i+=1
    while j<n2:
        arr[k]=R[j]
        k+=1
        j+=1

def MergeSort(arr,l,r):
    if l<r:
        m=(l+r)//2
        MergeSort(arr,l,m)
        MergeSort(arr,m+1,r)
        merge(arr,l,m,r)

iterable=[
    Product("Ceapa","leguma",5),
    Product("Morcov","leguma",5),
    Product("Gulie","leguma",5),
    Product("Patrunjel", "leguma", 5),
    Product("Copil", "leguma", 10),
    Product("Mar", "fruct", 2),
    Product("Copil", "fruct", 3),
    Product("Cutit", "solutie", 10),
    Product("Rodie", "fruct", 10),
    Product("Copil", "om", 100)
]

MergeSort(iterable,0,9)
#bubble(iterable)
for i in iterable:
    print(i)