#include<bits/stdc++.h>
using namespace std;                                             
string LCS(string x, string y, int m, int n) {
	int maxLen = 0;
	int endIndex = m;
	int lookup[m + 1][n + 1];
	memset(lookup, 0, sizeof(lookup));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				lookup[i][j] = lookup[i - 1][j - 1] + 1;
				if (lookup[i][j] > maxLen) {
					maxLen = lookup[i][j];
					endIndex = i;
				}
			}

		}
	}
	return x.substr(endIndex - maxLen, maxLen);
}

int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << LCS(x, y, m, n);
}