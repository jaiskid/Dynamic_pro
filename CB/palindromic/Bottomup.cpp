#include<bits/stdc++.h>
using namespace std;
int LcsLength(string x, string y, int n) {
	int lookup[n + 1][n + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				lookup[i][j] = 0;
			if (x[i - 1] == y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;
			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}
	for (auto i : lookup) {
		cout << i << " ";
	}
	return lookup[n][n];
}
int main() {
	string x;
	cin >> x;
	int m = x.size();
	string y;
	y = x;
	reverse(y.begin(), y.end());
	cout << LcsLength(x, y, m);
}