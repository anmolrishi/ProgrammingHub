fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib a = fib (a-2) + fib (a-1)

