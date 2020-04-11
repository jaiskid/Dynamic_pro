#include<bits/stdc++.h>
using namespace std;
int minCoins(int *Coins, int m, int n) {
	//base case
	if (n == 0) {
		return 0;
	}
	//initialize result
	int res = INT_MAX;
	for (int i = 0; i < m; i++) {
		if (Coins[i] <= n) {
			int sub_res = 1 + minCoins(Coins, m, n - Coins[i]);
			res = min(sub_res, res);
		}
	}
	return res;
}
int main() {
	int m;
	cin >> m;
	int Coins[10005];
	for (int i = 0; i < m; i++)
		cin >> Coins[i];
	int n;
	cin >> n;

	cout << minCoins(Coins, m, n);
}