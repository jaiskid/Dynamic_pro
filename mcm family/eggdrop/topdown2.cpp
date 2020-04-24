#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
int solve(int e, int f) {
	if (f == 0 || f == 1) {
		return f;
	}
	if (e == 1)
		return f;
	if (e == 0)
		return 0;
	if (t[e][f] != -1)
		return t[e][f];
	int mn = INT_MAX;
	int low;
	int high;
	for (int k = 1; k <= f; k++) {
		if (t[e - 1][k - 1] != -1) {
			low = t[e - 1][k - 1];
		}
		else {
			low = solve(e - 1, k - 1);
			t[e - 1][k - 1] = low;
		}
		if (t[e][f - k] != -1) {
			high = t[e][f - k];
		}
		else {
			high = solve(e, f - k);
			t[e][f - k] = high;
		}
		int temp = 1 + max(low, high);
		mn = min(temp, mn);
	}
	return	t[e][f] = mn;
}
int main() {
	memset(t, -1, sizeof(t));
	int e, f;
	cin >> e >> f;
	cout << solve(e, f);
}