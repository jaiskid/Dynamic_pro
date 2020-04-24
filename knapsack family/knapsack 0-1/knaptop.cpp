#include<bits/stdc++.h>
using namespace std;
int static t[100][1001];
int knapsack(int *wt, int *val, int w, int n) {
	if (n == 0 or w == 0)
		return 0;
	if (t[n][w] != -1)
		return t[n][w];
	if (wt[n - 1] <= w) {
		return t[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
	}
	else if (wt[n - 1] > w)
		return t[n][w] = knapsack(wt, val, w, n - 1);
}
int main() {
	memset(t, -1, sizeof(t));
	int n;
	cin >> n;
	int wt[n];
	for (int i = 0; i < n; i++) {
		cin >> wt[i];
	}

	int val[n];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int w;
	cin >> w;
	cout << knapsack(wt, val, w, n);
}