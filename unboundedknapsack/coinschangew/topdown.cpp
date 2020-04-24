#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int ways(int *coins, int sum, int n) {
	if (n == 0 and sum != 0)
		return 0;
	if (sum == 0)
		return 1;
	if (t[n][sum] != -1)
		return t[n][sum];
	if (coins[n - 1] <= sum)
		return t[n][sum] = ways(coins, sum - coins[n - 1], n) + ways(coins, sum, n - 1);
	else if (coins[n - 1] > sum)
		return t[n][sum] = ways(coins, sum, n - 1);
}
int main() {
	memset(t, -1, sizeof(t));
	int n;
	cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	int sum;
	cin >> sum;
	cout << ways(coins, sum, n);
}