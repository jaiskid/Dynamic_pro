#include<bits/stdc++.h>
using namespace std;
int dp[20000000];
void minStep(int n) {
	dp[1] = 1;
	dp[0] = 0;
	//Iterate over all possible number starting from 2
	for (int i = 2; i <= 2 * 10000000; i++) {

		dp[i] = 1 + dp[i - 1];
		if (i % 2 == 0) {
			dp[i] = min(dp[i], 1 + dp[i / 2]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3]);
		}
	}
	return;
}
int main() {
	int t;
	cin >> t;	while (t--) {
		int n;
		cin >> n;
		minStep(n);
		cout << dp[n] << endl;
	}
}