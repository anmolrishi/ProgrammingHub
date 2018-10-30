#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector< vector<ll> > Matrix;
const int N = 2;
const ll mod = 1e9 + 7;
const Matrix mfib = {{1, 1}, {1, 0}};
const Matrix midn = {{1, 0}, {0, 1}};

ll gcd(ll a, ll b) {return !a ? b : gcd(b%a, a);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a, b);}

unordered_map<ll, ll> memo;

inline Matrix mult(const Matrix& a, const Matrix& b, ll MOD = mod) {
	Matrix ans = {{0, 0}, {0, 0}};
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			ll sum = 0;
			for(int k = 0; k < N; k++) {
				sum += a[i][k]*b[k][j] % MOD;
			}
			ans[i][j] = sum;
		}
	}
	return ans;
}

inline ll fib(ll n) {
	if(memo.count(n)) return memo[n];
	Matrix ans = midn, aux = mfib;
	for(ll e = n; e; e >>= 1) {
		if(e & 1) {
			ans = mult(ans, aux);
		}
		aux = mult(aux, aux);
	}
	if(n) memo[n-1] = ans[1][1];
	memo[n+1] = ans[0][0];
	return memo[n] = ans[0][1];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n;
	for(int TC = 1; cin >> n; TC++) {
		printf("Case: %d\n", TC);
		printf("fib(%lld) = %lld\n\n", n, fib(n));
	}
	return 0;
}
