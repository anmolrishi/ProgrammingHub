#include <iostream>

int fib(int x)
{
  if (x == 0)
    return 0;
  if (x <= 1)
    return x;
  return fib(x - 1) + fib(x - 2);
}

int main()
{
  for (int i = 0; i < 10; i++)
  {
    std::cout << fib(i) << std::endl;
  }
  return 0;
}
