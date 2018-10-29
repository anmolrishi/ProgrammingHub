/*
 * C++ program to generate fibonacci series upto 1000
   You can change the end value eg;(fib1+fib2 > n)
 */
#include<iostream>
using namespace std;
 
int main()
{   /* declaring the 3 values */ 
    int fib1 = 0, fib2 = 1, fib3 = 1;
 
    cout << "The Fibonacci Series is follows : " << endl << fib1 << " " << fib2 << " ";
    while (fib1 + fib2 < 1000)
    {
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
        cout << fib3 << " ";
    }
    /* Printing the sequence */
    cout << endl;
 
    return 0;
}
