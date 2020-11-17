// Time O(m*n)
#include<bits/stdc++.h>
using namespace std;
static int dp[1005][1005];
int lcs(string x, string y, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (dp[m][n] != -1)
		return dp[m][n];
	if (x[m - 1] == y[n - 1])
		return dp[m][n] = lcs(x, y, m - 1, n - 1) + 1;
	return dp[m][n] = max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
}
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	memset(dp, -1, sizeof dp);
	cout << lcs(x, y, m, n);
}