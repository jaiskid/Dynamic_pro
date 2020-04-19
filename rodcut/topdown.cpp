#include<bits/stdc++.h>
using namespace std;
int t[10005];
int cost;
int rodcut(int *prices, int rod) {
	if (rod == 0)
		return 0;
	if (t[rod] != -1) {
		return t[rod];
	}

	int maxValue = INT_MIN;
	for (int i = 1; i <= rod; i++) {
		return t[rod] = cost = prices[i - 1] + rodcut(prices , rod - i);
		maxValue = min(maxValue, cost);
	}
	return  t[rod] = maxValue;
}
int main() {
	memset(t, -1, sizeof(t));
	int rod;
	cin >> rod;
	int n;
	cin >> n;
	int prices[n];
	for (int  i = 0; i < n; i++)
		cin >> prices[i];
	cout << rodcut(prices, rod);

}