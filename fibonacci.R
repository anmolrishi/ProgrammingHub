#fibonacci sequence

fib <- function(n)
{
  if( n == 0)
  {
    return(n)
  }
  if( n == 1)
  {
    return(n)
  }
  return(fib(n-1)+fib(n-2))
}

#tests
fib(5)
fib(15)
fib(2)
fib(0)
fib(100)







