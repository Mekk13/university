import math

"""
Suciu Maria Alexia
I am very basic, so I will pick the following:

f(x)=x^2 for my convex function
g(x)=sin(x)-sin(2x) for my nonconvex function

for the notation of eta I will be using h
gradient descent method: xn+1=xn-h*f'(xn)
"""

def fx(x):
    return x**2

def fx_differentiated(x):
    return 2*x

def gx(x):
    return math.sin(x)-math.sin(2*x)

def gx_differentiated(x):
    return math.cos(x)-2*math.cos(2*x)

def gradient_descent(x,h,value):
    """
    subprogram that computes the gradient descent until convergence
    :param x: the initial x value which is plugged in f(x)
    :param epsilon: epsilon <3
    :param h: the step size
    :param value: checks if we're working with f(x) or g(x) , 1 and 0
    :return: the number of steps and the minimum
    """
    epsilon = 0.0000001  # I will use an epsilon to figure out when f'(x)->0 , so : |xn+1-xn|<epsilon
    xn=x
    if value:
        xn1 = xn - h * fx_differentiated(xn)  # Xn+1
    else:
        xn1 = xn - h * gx_differentiated(xn)  # Xn+1

    nr_of_steps=1 #We made one step already by computing the first Xn+1
    max_number_of_steps=10000
    # if our step is too big, the gradient descent might diverge thus entering an infinite loop
    #example: h>0.5 and xn=1 => xn+1=xn(1-2*h) ; 1-2*h can become

    while abs(xn1 - xn) >= epsilon:
        nr_of_steps += 1
        xn = xn1
        if value:
            xn1 = xn - h * fx_differentiated(xn)  # Xn+1
        else:
            xn1 = xn - h * gx_differentiated(xn)
        if nr_of_steps >= max_number_of_steps or abs(xn)>10000:
            raise ValueError("The step was too big and the method can not converge")
    if value:
        minimum = round(fx(xn))  # f(x0) where f'(x0)->0
    else:
        minimum = round(gx(xn),7)  # g(x0) where g'(x0)->0
    return nr_of_steps, minimum

def execute_gradient_descent(value):
    """
    executes the gradient descent method function, checks for invalid inputs and prints the results
    :param value: a value that is responsible for the program using f(x) or g(x)
    :return: -
    """
    try:
        h = float(input("Enter the step (h): "))
        if h < 0:
            raise ValueError()
        x = float(input("Enter the initial value x:"))
        try:
            nr_of_steps, minimum = gradient_descent(x,h,value)
            print(" Number of steps: ", nr_of_steps, '\n', "Converges to: ", minimum)
        except ValueError:
            print("Error: The step was too big and the method can not converge")
    except ValueError:
        print("Please enter a valid number")


def nonconvex_g():
    step1,min1=gradient_descent(1,0.1,0)
    step2,min2=gradient_descent(4,0.1,0)
    print("for x0=1 the gradient descent converges method to: ", min1)
    print("for x0=4 the gradient descent converges method to: ", min2)

def menu():
    print("pick what you wish to do:")
    print("1. Find convergence to the minimum of a convex function: x^2")
    print("2. Find convergence to the minimum of a nonconvex function: sin(x)-sin(2x)")
    print("3. Visualize g(x)")
    print("4. Exit \n ")

def main():

    commands={
        "1": lambda: execute_gradient_descent(1),
        "2": lambda: execute_gradient_descent(0),
        "3": lambda: nonconvex_g(),
        "4": lambda: exit()
    }
    while True:
        menu()
        command_text=input("Enter your choice: ").strip()
        if command_text in commands:
            commands[command_text]()
main()
