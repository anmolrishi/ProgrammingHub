#include <bits/stdc++.h>
using namespace std;
int main(){
	string str, answer = ""; 
	cin >> str;
	for (int i = 0; i < str.size(); i++){
        string subst = ""; set<char>check;
        for (int j = i; j < str.size(); j++){
            subst += str[j];
            check.insert(str[j]);
            if (subst.size() == check.size() && subst.size() > answer.size()){
                answer = subst;
            }
        }
	}
	cout << answer << '\n';
	return 0;
}
