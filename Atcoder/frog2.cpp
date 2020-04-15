#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int x[110000];
	int dp[110000];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i <= n; i++)
		dp[i] = INT_MAX;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i + j < n)
				dp[i + j] = min(dp[i + j], dp[i] + abs(x[i] - x[i + j]));
		}
	}
	cout << dp[n - 1];
}