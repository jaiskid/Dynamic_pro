#include<bits/stdc++.h>
using namespace std;
int rodcut(int *prices, int n) {
	//T[i-1] Stores maximum profit acheived from rod of length
	int T[n + 1];
	for (int i = 0; i < n + 1; i++) {
		T[i] = 0;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j <= i ; j ++) {
			T[i] = max(T[i], prices[j - 1] + T[i - j]);
		}
	}
	return T[n];
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