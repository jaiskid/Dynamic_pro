#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int t[N][N];
int Minpath(int m, int n) {
	if (m == 0 and n == 0) {
		return 1;
	}
	if (m < 0 || n < 0) {
		return 0;
	}
	if (t[m][n] != -1) {
		return t[m][n];
	}

	return t[m][n] = Minpath(m - 1, n) + Minpath(m, n - 1);
}
int main() {
	memset(t, -1, sizeof(t));
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, n;
	cin >> m >> n;
	cout << Minpath(m, n);
	memset(t, -1, sizeof(t));
}
