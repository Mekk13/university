import math
"""
Suciu Maria-Alexia
f(x)= e^(-x^2)
f(-x)= e^(-(-x)^2)=e^(-x^2)=f(x)
=> f(x) is an even function (1)

integral from -inf to inf of f(x)= integral from -inf to 0+ integral from 0 to +inf of f(x)
but f(x)=f(-x)(1) => integral from -inf to inf of f(x)= 2*integral from 0 to +inf of f(x) (2)

"""
def f(x):
    return math.e ** (-(x**2))

def trapezium_rule(a,b,n):
    """
    Function that uses the trapezium rule to approximate the area of the function f(x) on a given interval
    :param a: start of the interval
    :param b: end of the interval
    :param n: number of sub-intervals into which [a,b] is divided
    :return: the approximation of the integral
    """
    dx=(b-a)/n
    integral=(f(a) + f(b))/2
    for k in range(1,n): # it will go from 1 to n-1
        integral+=f(a+k*dx) # Xk= a+k*dx, k from 1 to n-1, when k is 0 or n we get a and
    integral*=dx
    return integral

def trapezium_to_inf():
    """
    Function that attempts to calculate the area of the function f(x) from -inf to +inf
    :return: approximated value of the area
    """
    a=0
    b=10
    n=10000
    sum_of_integrals=0
    for i in range(1,6):
        integral=trapezium_rule(a,b,n)
        sum_of_integrals+=integral
        a=b
        b*=2
        n*=2
    return sum_of_integrals*2 # We return the result multiplied by 2 due to (2) mentioned above

def main():
    integral_value=trapezium_to_inf()
    print("Approximateed area: ", integral_value)
    print("Sqrt(pi): ",math.sqrt(math.pi))

main()