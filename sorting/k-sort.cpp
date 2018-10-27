#include <iostream>
#include <queue>
using namespace std;


void ksort(int *arr, int n, int k);
{
	priority_queue <int, vector <int> , greater <int> > pq(arr, arr+k+1);
	int index = 0;

	for (int i = k+1; i < n; ++i)
	{
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}	

	while(!pq.empty())
	{
		arr[index++] = pq.top();
		pq.pop();
	}
}
int main()
{
	int n;
	cout << "No. of elements: ";
	cin >> n;

	int *arr = new arr[n];

	cout << "Enter " << n << " elements." << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int k;
	cout << "Enter k : ";
	cin >> k;

	ksort(arr, n, k);

	cout << "Sorted Array: " << endl;
 	for(auto &ref: arr)
		cout << ref << "\t";
	cout << endl;
	return 0;
}