#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int A[110000];
	int B[110000];
	int C[110000];
	int dp[110000][3];

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> B[j];
	}
	for (int k = 0; k < n; k++) {
		cin >> C[k];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				if (j == 0) dp[i][j] = A[i];
				else if (j == 1) dp[i][j] = B[i];
				else dp[i][j] = C[i];
			} else {
				for (int k = 0; k < 3; k++) {
					if (j == k) continue;
					if (j == 0) dp[i][j] = max(dp[i][j], dp[i - 1][k] + A[i]);
					else if (j == 1) dp[i][j] = max(dp[i][j], dp[i - 1][k] + B[i]);
					else  dp[i][j] = max(dp[i][j], dp[i - 1][k] + C[i]);
				}
			}
		}
	}
	int ret = 0;
	ret = max(ret, dp[n - 1][0]);
	ret = max(ret, dp[n - 1][1]);
	ret = max(ret, dp[n - 1][2]);

	cout << ret;
}