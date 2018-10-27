include <iostream>
using namespace std;

int main()
{
    int n, t1 = 0, t2 = 1, nt = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "FIBONACCI SERIES: ";

    for (int i = 1; i <= n; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if(i == 2)
        {
            cout << t2 << " ";
            continue;
        }
        nt = t1 + t2;
        t1 = t2;
        t2 = nt;
        
        cout << nt << " ";
    }
    return 0;
}
