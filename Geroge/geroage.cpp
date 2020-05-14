#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, k;
const int N = 5005;
ll dp[N][N];
ll a[N];
ll george(ll i, ll count_k) {
	if (i > n - m || count_k == k)
		return 0;
	if (dp[i][count_k] != -1)
		return dp[i][count_k];
	ll op1 = 0, op2 = 0;
	for (ll k = i; k < i + m; k++) {
		op1 += a[k];
	}
	op1 += george(i + m, count_k + 1);
	op2 = george(i + 1, count_k);
	dp[i][count_k] = max(op1, op2);
	return max(op2, op1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k ;
	for (int i = 0; i < n; i++)cin >> a[i];
	cout << george(0, 0);
}
