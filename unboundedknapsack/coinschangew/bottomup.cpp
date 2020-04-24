#include<bits/stdc++.h>
using namespace std;
int ways(int *coins, int sum, int n) {
	int t[n + 1][sum + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < sum + 1; j++) {
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {
			if (coins[i - 1] <= j)
				t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
			else if (coins[i - 1] > j)
				t[i][j] = t[i - 1][j];
		}
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < sum + 1; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	return t[n][sum];
}
int main() {
	int n;
	cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	int sum;
	cin >> sum;
	cout << ways(coins, sum, n);
}