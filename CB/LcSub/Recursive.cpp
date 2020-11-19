#include<bits/stdc++.h>
using namespace std;
int lcsubs(string x, string y, int m, int n, int count) {
	if (m == 0 || n == 0) {
		return count;
	}
	if (x[m - 1] == y[n - 1])
		return count = lcsubs(x, y, m - 1, n - 1, count + 1);
	else
		return max(count, max(lcsubs(x, y, m - 1, n, 0), lcsubs(x, y, m, n - 1, 0)));
}

int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << lcsubs(x, y, m, n, 0);
}