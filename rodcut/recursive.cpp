#include<bits/stdc++.h>
using namespace std;
int rodcut(int *prices, int n) {
	if (n == 0)
		return 0;
	int maxValue = INT_MIN;
	//the function work on the value of i and n-i every time
	for (int i = 1; i <= n; i++) {
		int cost = prices[i - 1] + rodcut(prices, n - i);
		maxValue = max(maxValue, cost);
	}
	return maxValue;
}
int main() {
	int rod;
	cin >> rod;
	int n;
	cin >> n;
	int prices[n];
	for (int i = 0; i < n; i++)
		cin >> prices[i];
	cout << rodcut(prices, rod);
}