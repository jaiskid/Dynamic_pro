#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll count(ll n) {
	ll endwithzero[n], endwithone[n];
	endwithone[0] = 1;
	endwithzero[0] = 1;
	for (int i = 1; i <= n; i++) {
		endwithzero[i] = endwithzero[i - 1] + endwithone[i - 1];
		endwithone[i] = endwithzero[i - 1];
	}
	return endwithzero[n - 1] + endwithone[n - 1];
}
int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << count(n) << endl;
	}
}