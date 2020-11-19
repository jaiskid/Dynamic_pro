#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001][1001];
int lcsubstring(string x, string y, int m, int n, int count) {
	if (m == 0 || n == 0)
		return count;
	if (t[m][n][count] != -1)
		return t[m][n][count];
	if (x[m - 1] == y[n - 1])
		count = lcsubstring(x, y, m - 1, n - 1, count + 1);
	return t[m][n][count] = max(count, max(lcsubstring(x, y, m - 1, n, 0), lcsubstring(x, y, m, n - 1, 0)));
}
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	memset(t, -1, sizeof t);
	cout << lcsubstring(x, y, m, n, 0);
}