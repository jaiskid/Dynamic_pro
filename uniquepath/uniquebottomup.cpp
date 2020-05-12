#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 1005;
ll t[N][N];
ll UniquePath(ll m, ll n) {
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 1;
		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			t[i][j] = t[i - 1][j] + t[i][j - 1];
		}
	}
	// for (int i = 0; i < m + 1; i++) {
	// 	for (int j = 0; j < n + 1; j++) {
	// 		cout << t[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return t[m][n];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, n;
	cin >> m >> n;
	cout << UniquePath(m, n);
}
