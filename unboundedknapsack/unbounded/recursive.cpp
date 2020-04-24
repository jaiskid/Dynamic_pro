#include<bits/stdc++.h>
using namespace std;
int unbounded(int *wt, int *val, int w, int n) {
	if (n == 0 || w == 0)
		return 0;
	if (wt[n - 1] <= w)
		return max(val[n - 1] + unbounded(wt, val, w - wt[n - 1], n), unbounded(wt, val, w, n - 1));
	else if (wt[n - 1] > w)
		return unbounded(wt, val, w, n - 1);
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
	cout << unbounded(wt, val, w, n);

}