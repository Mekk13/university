"""
def div_q(data):
    if size(data):
        #solve the problem directly
        # base case
        return rez
    #decompose data
    rez1=div_q(div1)
    #...
    rezn=div_q(divn)
    return combine(rez1,...,rezn)


def find_max(data:list)-> int:
    if len(data)=1:
        return data[0]
    max_val=find_max(data[1:])
    return max(max_val,data[0])
#T(n) = T(n-1)+n..+1.+n-1..+1.+n-2 +1... => O(n^2) ; the +1 is the stack!  space complx = n
#1000 values or less because of the stack
"""

#return the product of the positive numbers on even positions
data = [-2,-1,5,8,-6,-5,2,-4,-3,10,11]

def pb(data:list, index=0)-> int:
    """

    :param data: the list
    :return: the product <333
    """
    if len(data-index)<3:
        if data[index]>0 :
            return data[index]
        else:
            return 1
    #or, you can simply
    #return data[index] if data[index]>0 else 1
    return (data[index] if data[index]>0 else 1)* pb(data, index+2)
#each recursive call puts a 1 on the stack <3

def product_divide_halves_impl1(data:list, left:int, right:int)->int:
    if left==right:
        return data[left] if data[left]>0 and left%2==0 else 1
    m=(left+right)//2
    return product_divide_halves_impl1(data,left,m) *product_divide_halves_impl1(data,m+1,right)

def product_divide_halves(data: list) -> int:
    return product_divide_halves_impl1(data,0,len(data)-1)

#T(n)=2*T(n/2)+1
#no extra space complexity
#if we keep in mind the stack: log2(n)

def product_divide_halves_iter(data:list)->int:
    stack = [(0, len(data)-1)]
    product=1

    while len(stack)>0:
        left, right=stack.pop()
        if left==right:
            product*=data[left] if data[left]>0 and left%2==0 else 1
        else:
            m=(left+right)//2
            stack.append(left,m)
            stack.append(m+1,right)
            max_stack = max(max_stack,len(stack))
    return max_stack, product #returns a touple

print(product_divide_halves(data))