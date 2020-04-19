#include<bits/stdc++.h>
using namespace std;
int lsubstrting(string x, string y, int m, int n, int count) {
	if (m == 0 || n == 0)
		return count;
	if (x[m - 1] == y[n - 1])
		return lsubstrting(x, y, m - 1, n - 1, count + 1);
	else
		return count = max(count, max(lsubstrting(x, y, m - 1, n, 0), lsubstrting(x, y, m, n - 1, 0)));
}
int main() {
	string x;
	string y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << lsubstrting(x, y, m, n, 0);
}