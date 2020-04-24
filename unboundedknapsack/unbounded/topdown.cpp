#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
int unbounded(int *wt, int *val , int w, int n) {
	if (n == 0 || w == 0)
		return 0;
	if (t[n][w] != -1)
		return t[n][w];
	if (wt[n - 1] <= w)
		return t[n][w] = max(val[n - 1] + unbounded(wt, val, w - wt[n - 1], n), unbounded(wt, val, w, n - 1));
	if (wt[n - 1] > w)
		return t[n][w] = unbounded(wt, val, w, n - 1);
}
int main() {
	memset(t, -1, sizeof(t));
	int n;
	cin >> n;
	int wt[n];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	int val[n];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int w;
	cin >> w;
	cout << unbounded(wt, val, w, n);
}