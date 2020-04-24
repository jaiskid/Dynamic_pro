#include<bits/stdc++.h>
using namespace std;
int knapsack(int *wt, int *val, int w, int n) {
	//base cases  for smaller problem will be zero this is because either bag capacity can be 0 or can be no item is present
	if (w == 0 || n == 0)
		return 0;
	//choice diagram
	if (wt[n - 1] <= w) {
		return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
	} else if (wt[n - 1] > w) {
		return knapsack(wt, val, w, n - 1);
	}
}
int main() {
	int n;
	cin >> n;
	int wt[n];
	int val[n];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int w;
	cin >> w;
	cout << knapsack(wt, val, w, n);
}