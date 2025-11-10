from random import randint

"""
# list implementation
def generate_number(real:int, imag:int):
    return [real,imag]

def get_real_p(number:list):
    return number[0]

def get_imag_p(number:list):
    return number[1]
"""
#dictionary implementation

def generate_number(real:int, imag:int):
    return {'real':real, 'imag':imag}

def get_real_p(number:dict):
    return number['real']

def get_imag_p(number:dict):
    return number['imag']

def get_input(message:str)->int:
    while True:
        try:
            value=int(input(message)) #try to convert input to int
            return value #if it works return it
        except ValueError:
            print('Please enter a valid number')

def add_number(nr_list:list):
    real=get_input("Real part:")
    imag=get_input("Imaginary part:")
    new=generate_number(real,imag)
    nr_list.append(new)

def get_amount_of_numbers()->int:
    while True:
        try:
            n=get_input("How many numbers would you like to add? :")
            break
        except ValueError:
            print('Please enter a valid number')
    return n

def create_list(list_of_numbers:list):
    list_of_numbers.clear()
    n=get_amount_of_numbers()
    for i in range(n):
        add_number(list_of_numbers)

def to_str(number):
    real=get_real_p(number)
    imag=get_imag_p(number)
    if imag<0:
        return str(real)+"-"+str(-imag)+"i"
    else:
        return str(real)+"+"+str(imag)+"i"


def print_numbers(numbers: list):
    for i in range(len(numbers)):
        print(f"{i+1})",to_str(numbers[i]))


def generate_random_list(nr_of_elements,arr:list):
    arr.clear()
    for i in range(nr_of_elements):
        real=randint(-100,100)
        imag=randint(-100,100)
        number=generate_number(real,imag)
        arr.append(number)

def longest_distinct_subarray(arr:list):
    """
    Function that finds the longest subarray of distinct elements of a given array
    :param arr: the original array
    :return: the length of the longest subarray and the subarray
    """
    found = []
    start=0
    max_len=0
    for end in range(len(arr)):
        r=get_real_p(arr[end])
        i=get_imag_p(arr[end])
        number=(r,i)
        while number in found:
            found.remove(number)
            start+=1
        found.append(number)
        max_len = max(max_len, end-start+1)
    return max_len,found


def execute_longest_dist_subarray(arr:list):
    """
    Function that executes the function that finds the longest subarray of distinct elements of a given array
    :param arr: the original array
    :prints: the length of the longest subarray and the subarray
    :return: -
    """
    maxi,elements=longest_distinct_subarray(arr)
    print("The longest distinct subarray has the length ",maxi," and can be:")
    print(elements)

def max_subarray_sum(arr:list):
    """
    Function that finds the subarray with the maximum sum (and this sum) of a given array
    :param arr: original array
    :return: maximum sum and its corresponding subarray
    """
    if len(arr)==0:
        return 0,""
    start=0
    stop=0
    temp_start=0
    current_sum=0
    max_sum=float('-inf')
    for i in range(len(arr)):
        r=get_real_p(arr[i])
        if current_sum+r<r:
            temp_start=i
            current_sum=r
        else:
            current_sum+=r
        if current_sum>max_sum:
            max_sum=current_sum
            stop=i
            start=temp_start
    return max_sum,start,stop



def execute_max_subarray_sum(arr:list):
    """
    Function that executes the function that finds the subarray with the maximum sum of a given array
    :param arr: original array
    :prints: the maximum sum of a subarray and the subarray
    :return: -
    """
    maxi,start,stop=max_subarray_sum(arr)
    print("The subarray with the maximum sum of real parts is: ")
    print(arr[start:stop+1])
    print("The sum is: ",maxi)

def menu():
    print("")
    print("What would you like to do?")
    print("1. Read a list of complex numbers")
    print("2. Generate a random list of numbers")
    print("3. Display the list of numbers")
    print("4. Display the longest distinct subarray")
    print("5. Display maximum sum subarray")
    print("6. Exit")
    print("")

#Testers

def test_generate_number():
    r=3
    i=78
    number=generate_number(r,i)
    imag=get_imag_p(number)
    real=get_real_p(number)
    assert real==r
    assert imag==i

def test_to_str():
    x=generate_number(2,4)
    y=to_str(x)
    assert y=="2+4i"

def test_longest_distinct_subarray():
    n1=generate_number(2,3)
    n2=generate_number(7,0)
    n3=generate_number(0,1)
    n4=generate_number(7,0)
    array=[n1,n2,n3,n4]
    max_len,found=longest_distinct_subarray(array)
    assert max_len==3

def test_max_subarray_sum():
    n1 = generate_number(2, 3)
    n2 = generate_number(7, 0)
    n3 = generate_number(-3,-19)
    n4 = generate_number(-5, 0)
    array = [n1, n2, n3, n4]
    sum,start,stop=max_subarray_sum(array)
    assert sum==9
    assert start==0
    assert stop==1


def main():
    test_generate_number()
    test_to_str()
    test_longest_distinct_subarray()
    test_max_subarray_sum()

    arr=[]
    commands={
        "1": lambda: (create_list(arr),print("List created successfully!")),
        "2": lambda: (generate_random_list(int(input("How many elements would you like to generate? :")),arr), print("List generated successfully!")),
        "3": lambda: print_numbers(arr),
        "4": lambda: execute_longest_dist_subarray(arr),
        "5": lambda: execute_max_subarray_sum(arr),
        "6": lambda: exit(),
    }

    while True:
        menu()
        command_text=input("Pick an option: ").strip()
        if command_text in commands:
            if command_text=="2" or command_text=="1" and len(arr)!=0:
                print("This will erase any previous elements and generate a new list. Do you wish to continue?")
                answer=input("Yes or No: ")
                if answer=="Yes":
                    commands[command_text]()
            else:
                commands[command_text]()
        else:
            print("Please enter a valid option!")
main()
