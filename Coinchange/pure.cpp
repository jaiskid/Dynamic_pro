#include<bits/stdc++.h>
using namespace std;
int dp[10005] = {0};
int mincoins(int *coins, int n, int m) {
	for (int i = 0; i <= n; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (coins[j] <= i) {
				dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
			}

		}

	}
	for (int i = 1; i <= n; i++)
		cout << i << " " << dp[i] << endl;
	return dp[n];
}
int main() {
	int m;
	cin >> m;
	int Coins[10005];
	for (int i = 0; i < m; i++)
		cin >> Coins[i];
	int n;
	cin >> n;

	cout << mincoins(Coins, n, m);
}