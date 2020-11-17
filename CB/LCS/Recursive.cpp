// O(2^(m+n))
#include<bits/stdc++.h>
using namespace std;
int lcsLength(string x, string y, int m, int n) {
	if (m == 0 || n == 0) {
		return 0;
	}
	if (x[m - 1] == y[n - 1])
		return lcsLength(x, y, m - 1, n - 1) + 1;
	return max(lcsLength(x, y, m - 1, n), lcsLength(x, y, m, n - 1));
}
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << lcsLength(x, y, m, n);
}