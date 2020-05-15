#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double dp[2001][2001] = {0};
int n, t;
double p;
double solve() {
	dp[0][0] = 1; //this is the case when time and people is zero
	//here j is people and i==time
	for (int i = 1; i <= t; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == n) { //for the nth case
				dp[i][j] = p * dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else if (j == 0) { //this means there is no people on escalator at any time t
				dp[i][j] = (1 - p) * dp[i - 1][j];

			}
			else {
				dp[i][j] = p * dp[i - 1][j - 1] + (1 - p) * dp[i - 1][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	double ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += i * dp[t][i];
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> p >> t;
	cout << fixed << setprecision(8) << solve() << endl;
	return 0;

}
