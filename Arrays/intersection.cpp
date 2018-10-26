#include <iostream>
#include <vector>
#include <unordered_multiset>
#include <sstream>
using namespace std;

/*
    input:
        2 5 7 3 4 5 6 3 7 5 7
        2 5 9 7 3 1 6 7
    output:
        6 2 7 7 5 3
*/

vector<int> intersection(const vector<int>& a, const vector<int>& b)
{
    unordered_multiset<int> ma, mb;
    for (int k : a) ma.insert(k);
    for (int k : b) {
        if (ma.count(k)) mb.insert(k);
    }
    vector<int> v;
    for (auto it : mb) v.push_back(*it);
    return v;
}

int main()
{
    string sa, sb;
    vector<int> a, b;
    getline(cin, sa);
    getline(cin, sb);
    stringstream ia(sa), ib(sb);
    int k;
    while (ia >> k) a.push_back(k);
    while (ib >> k) b.push_back(k);
    for (int j : intersection(a,b)) {
        cout << j << ' ';
    }
    cout << endl;
}