def fib(n):
  if n == 0:
      return 0
# r[i] contains the value of ith Fibonacci number
  r = [-1]*(n + 1)
  r[0] = 0
  r[1] = 1
  for i in range(2, n + 1):
      r[i] = r[i - 1] + r[i - 2]
  return r[n]
n = int(input('Enter the value of n: '))
result = fib(n)
print('The nth Fibonacci number is:', result)