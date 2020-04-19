#include<bits/stdc++.h>
using namespace std;
int lcsprint(string x, string y, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (x[m - 1] == y[n - 1]) {
		cout << x[m - 1];
		cout << endl;
		return 1 + lcsprint(x, y, m - 1, n - 1);
	}
	return max(lcsprint(x, y, m, n - 1), lcsprint(x, y, m - 1, n));
}
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << lcsprint(x, y, m, n);
}