#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string Lcs(string x, string y, int m, int n) {
	if (m == 0 || n == 0)
		return string("");
	if (x[m - 1] == y[n - 1]) {
		return Lcs(x, y, m - 1, n - 1) + x[m - 1];
	}
	if (dp[m - 1][n] > dp[m][n - 1])
		return Lcs(x, y, m - 1, n);
	else
		return Lcs(x, y, m, n - 1);
}
void lcs(string x, string y) {
	int m = x.size();
	int n = y.size();

	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	// for (int i = 0; i < m + 1; i++) {
	// 	for (int j = 0; j < n + 1; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}
int main() {
	string x, y;
	cin >> x >> y;
	lcs(x, y);
	cout << Lcs(x, y, x.length(), y.length());
}