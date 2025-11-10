import numpy as np
import matplotlib.pyplot as plt

"""
I'm picking f(x)=x^2
"""

def f(x):
    return x**2

def f_first_derivative(x):
    return 2*x

def generate_h():
    """
    This will generate 10 proportionally(log) spaced numbers for h in decreasing order between 10^(-1) and 10^(-10)
    :param h_values: the generated array
    :return: h_values array
    """
    h_values=np.logspace(-1,-10,10)
    return h_values

def forward_difference(x,h):
    return (f(x+h)-f(x))/h

def centered_difference(x,h):
    return (f(x+h)-f(x-h))/(2*h)

def main():
    # Picking x=2
    x=2
    forward_errors=[]
    centered_errors=[]
    h_values=generate_h()
    h2_values=[]

    for h in h_values:
        forward_errors.append(abs(forward_difference(x,h)-f_first_derivative(x)))
        centered_errors.append(abs(centered_difference(x,h)-f_first_derivative(x)))
        h2_values.append(h**2)

    plt.figure(figsize=(10, 6))
    plt.loglog(forward_errors,label='Forward Error',marker='o')
    plt.loglog(centered_errors,label='Centered Error',marker='x')
    plt.loglog(h_values,label='h')
    plt.loglog(h2_values,label='h^2')
    plt.xlabel('Error')
    plt.ylabel('h')
    plt.legend()
    plt.show()
    """
    The errors increase as h decreases because the calculation involve smaller and smaller numbers.
    This can cause rounding errors in the computer's floating point arithmetic. 
    At a certain point these errors will outweigh the benefits of reducing h to increase precision.
    This is called the "machine precision error".
    """
main()