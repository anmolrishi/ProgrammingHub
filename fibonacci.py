num = int(input("How many fibonacci numbers? "))

def fib(n):
    a, b = 1, 1
    for _ in range(n):
        yield a
        a, b = b, a + b

print(list(fib(num)))
