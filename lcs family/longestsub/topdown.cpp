#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
int lcsubstring(string x, string y, int m, int n, int count) {
	if (m == 0 || n == 0)
		return count;
	if (x[m - 1] == y[n - 1])
		return t[m][n] = lcsubstring(x, y, m - 1, n - 1, count + 1);
	else
		return t[m][n] = count = max(count, max(lcsubstring(x, y, m - 1, n, 0), lcsubstring(x, y, m, n - 1, 0)));
}
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << lcsubstring(x, y, m, n, 0);
}