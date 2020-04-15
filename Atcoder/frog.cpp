#include<bits/stdc++.h>

using namespace std;
int main() {

	int n;
	cin >> n;
	int a[n];
	int sum;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int dp[n];
	dp[0] = 0;
	if (n == 1)
	{	cout << "0";
		return 0;
	}
	dp[1] = abs(a[1] - a[0]);
	for (int i = 2; i < n; i++)
	{

		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));

	}

	cout << dp[n - 1];

	return 0;
}
