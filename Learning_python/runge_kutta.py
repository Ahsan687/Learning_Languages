#defining a function 
def f(x, y):
    return x + y**2

# RK4 method implementation
def runge_kutta(x0, y0, x_target, h):
    x = x0
    y = y0

    while x < x_target:
        k1 = f(x, y)
        k2 = f(x + h/2, y + (h/2) * k1)
        k3 = f(x + h/2, y + (h/2) * k2)
        k4 = f(x + h, y + h * k3)
        
        y = y + (h/6) * (k1 + 2*k2 + 2*k3 + k4)
        x = round(x + h, 10)  # To avoid floating-point errors
    
    print(round(y, 6))

# Get user inputs and convert them to floats
x_target = float(input("For what value of x do you want to compute y? e.g., compute y at x = 0.3: "))
h = float(input("Enter the step size (h value): "))

# Initial conditions
x0 = 0
y0 = 0

# Compute y at the given x_target
runge_kutta(x0, y0, x_target, h)
