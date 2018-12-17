#include<iostream>

using namespace std;

// Function to calculate factorial 
unsigned long long int factorial(unsigned long long int value)
{
	unsigned long long int valueReturned = 1;

	for (unsigned long long int i = 1; i <= value; i++)
	{
		valueReturned *= i;
	}

	return valueReturned;
}

int main()
{
	unsigned long long int valueEntered;
	unsigned long long int value1, value2, value3;
	unsigned long long int finalValue;

	cout << "Welcome to Dyck Paths Calculator" << endl;

	do 
	{
		cout << "Enter value:                    ";

		cin >> valueEntered;

		if (valueEntered == 0)
		{
			break;
		}

		else if (valueEntered > 10)
		{
			cout << "Number of Dyck Paths outside of range for data type" << endl;
			cout << "Please enter values from range  1-10" << endl << endl;
		}

		else
		{
			value1 = factorial(2 * valueEntered);
			value2 = factorial(valueEntered + 1);
			value3 = factorial(valueEntered);

			finalValue = ((value1) / (value2 * value3));

			cout << "Number of Dyck Paths:           " << finalValue << endl << endl;
		}

	} while (valueEntered != 0);

	cout << "Goodbye";

	return 0;
}
