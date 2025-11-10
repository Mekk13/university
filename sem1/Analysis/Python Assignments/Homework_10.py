import numpy as np
import matplotlib.pyplot as plt

def custom_function(a, b, c):
    return 0.5 * (a**2 + c * b**2)

def compute_gradient(a, b, c):
    return np.array([a, c * b])

def execute_gradient_descent(start_a, start_b, c, step_size, num_steps):
    current_a = start_a
    current_b = start_b
    path = [(current_a, current_b)]
    for _ in range(num_steps):
        gradient = compute_gradient(current_a, current_b, c)
        current_a -= step_size * gradient[0]
        current_b -= step_size * gradient[1]
        path.append((current_a, current_b))
    return path

fig, axes = plt.subplots(2, 2, figsize=(10, 10))
axes = axes.ravel()

b_values = [1, 1/2, 1/5, 1/10]
index = 0
for constant_b in b_values:
    trajectory = execute_gradient_descent(1.0, 1.0, constant_b, 0.1, 200)
    trajectory = np.array(trajectory)
    a_vals = np.linspace(-1.5, 1.5, 500)
    b_vals = np.linspace(-1.5, 1.5, 500)
    A, B = np.meshgrid(a_vals, b_vals)
    Z = custom_function(A, B, constant_b)
    axes[index].contour(A, B, Z, 50)
    axes[index].plot(trajectory[:, 0], trajectory[:, 1], 'o-')
    axes[index].set_title(f'b = {constant_b}')
    index += 1
plt.tight_layout()  # Adjust the layout to minimize overlap
plt.show()
"""
As b gets smaller, the lines of the graph change shape becoming more oval and the gradient descent requires
more steps in order to reach the minimum value. Maria S.
"""