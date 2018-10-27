//Fibonacci Series using Recursion 
int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

//Fibonacci Series using Dynamic programming 
int fib_2(int n)
{
  if (n == 0)
		return 0;
	int *f = new int[n];
	int res;
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	res = f[n-1];
	delete[] f;
	return res;
}
