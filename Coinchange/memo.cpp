#include<bits/stdc++.h>
using namespace std;
int mincoins(int *coins, int n, int m, int *dp) {
	if (dp[n] != -1) {
		return dp[n];
	}
	if (n == 0)
		return 0;
	int res = INT_MAX;
	for (int i = 0; i < m; i++) {
		if (coins[i] <= n) {
			int sub_res = 1 + mincoins(coins, n - coins[i], m, dp);
			if (sub_res < res)
				res = sub_res;
		}
	}
	return dp[n] = res;
}
int main() {
	int m;
	cin >> m;
	int Coins[10005];
	for (int i = 0; i < m; i++)
		cin >> Coins[i];
	int n;
	cin >> n;
	int dp[10005];
	memset(dp, -1, sizeof(dp));
	cout << mincoins(Coins, n, m, dp);
}