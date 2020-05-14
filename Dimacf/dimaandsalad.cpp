#include<bits/stdc++.h>
using namespace std;
int shift = 1e5 + 2; //iski jarurat isliye he kyki negative number aa rahe he taste-k*cal karne se usko shift karengey positive me kyki negative element store karne nahi he
#define ll long long int
#define size 100001
const int N = 101;
ll dp[N][size];
ll n, k; //first line contain n and k
ll *taste, *cal; //pointer dynamicaly allocate karunga
ll Dimaandsalad(ll i, ll sum) {
	if (i == n) {
		if (sum == 0)
			return 0;
		return -1e12;
	}
	if (dp[i][sum + shift] != -1) {
		return dp[i][sum + shift];
	}
	//recursive
	ll op1 = taste[i]	+ Dimaandsalad(i + 1, (taste[i] - k * cal[i]) + sum);
	ll op2 = 0 + Dimaandsalad(i + 1, sum);
	dp[i][sum + shift] = max(op1, op2);
	return max(op1, op2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> k;
	taste = new ll[n];
	cal = new ll[n];
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++)cin >> taste[i];
	for (int i = 0; i < n; i++)cin >> cal[i];
	ll ans = Dimaandsalad(0, 0);
	if (ans <= 0)cout << -1;
	else
		cout << ans;
	cout << endl;
}
