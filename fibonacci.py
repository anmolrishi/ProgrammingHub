num = int(input("How many fibonacci numbers?")
          
def Fibonacci(n):
    if n <= 1:
        return n
    else:
        return Fibonacci(n-1) + Fibonacci(n-2)
print('Fibonacci = ' + str(Fibonacci(10)) )
