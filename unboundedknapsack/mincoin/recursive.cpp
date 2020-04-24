#include<bits/stdc++.h>
using namespace std;

int findMinCoins(int S[], int n, int sum)
{
	// if total is 0, no coins are needed
	if (sum == 0)
		return 0;

	// return INFINITY if total become negative
	if (sum < 0)
		return INT_MAX;

	// initialize minimum number of coins needed to infinity
	int coins = INT_MAX;

	// do for each coin
	for (int i = 0; i < n; i++)
	{
		// recur to see if total can be reached by including
		// current coin S[i]
		int res = findMinCoins(S, n, sum - S[i]);

		// update minimum number of coins needed if choosing current
		// coin resulted in solution
		if (res != INT_MAX)
			coins = min(coins, res + 1);
	}

	// return minimum number of coins needed
	return coins;
}

int main() {
	int n;
	cin >> n;
	int S[n];
	for (int i = 0; i < n; i++)
		cin >> S[i];
	int sum;
	cin >> sum;
	cout << findMinCoins(S, n, sum);
}