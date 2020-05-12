#include<bits/stdc++.h>
using namespace std;
int staircase(int *cost, int n) {
	for (int i = 0; i < n; i++) {
		if (i > 1) {
			cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
		}

	}
	int i = n;
	return min(cost[i - 1], cost[i - 2]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int cost[n];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	cout << staircase(cost, n);
}
