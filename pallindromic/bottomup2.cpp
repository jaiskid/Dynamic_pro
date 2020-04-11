#include<bits/stdc++.h>
using namespace std;
const int n = 1005;
bool dp[n][n];
int main() {
	int i, j, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;
	string s;
	cin >> s;
	for (i = 0; i < n; i++)
		dp[i][i] = true;
	for (int sz = 2; sz <= n; sz++) {
		for (i = 0; i + sz - 1 < n; i++) {
			int start = i, end = i + sz - 1;
			if (sz == 2) {
				dp[start][end] = (s[start] == s[end]);
			}
			else {
				dp[start][end] = (s[start] == s[end]) && (dp[start + 1][end - 1]);
			}
		}
	}
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << (dp[l][r] ? "YES" : "NO") << "\n";
	}
}