#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N];
int cost_(int *cost, int i, int n) {
	if (i >= n) return 0;
	if (dp[i] != -1)
	{
		return dp[i];
	}
	int op1 = INT_MAX;
	int op2 = INT_MAX;
	op1 = cost_(cost, i + 1, n) + cost[i];
	op2 = cost_(cost, i + 2, n) + cost[i];
	dp[i] = min(op1, op2);
	return dp[i];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int cost[n];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i <= n; i++) {
		dp[i] = -1;
	}
	int op1 = cost_(cost, 0, n);
	for (int i = 0; i <= n; i++) {
		dp[i] = -1;
	}
	int op2 = cost_(cost, 1, n);
	cout << min(op1, op2);


}
