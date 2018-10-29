#include <iostream>
#include <vector>
using namespace std;

void zeros_to_tail(vector<int>& v)
{
    int zeros = 0;
    int index = 0;
    for (int k : v) {
        if (k == 0) {
            ++zeros;
        }
        else {
            v[index++] = k;
        }
    }
    for (int i = 0; i < zeros; ++i) {
        v[index++] = 0;
    }
}

int main()
{
    vector<int> v = {1, 0, 2, 3, 4, 0, 0, 5, 1, 2, 1, 3, 0};
    cout << "Input: " << endl;
    for (int k : v) {
        cout << k << ' ';
    }
    cout << endl << "Output: " << endl;
    zeros_to_tail(v);
    for (int k : v) {
        cout << k << ' ';
    }
    cout << endl;
}