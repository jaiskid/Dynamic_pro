#include<bits/stdc++.h>
using namespace std;
int editDistance(string a, string b, int m, int n) {
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	if (a[m - 1] == b[n - 1])
		return editDistance(a, b, m - 1, n - 1);
	return 1 + min(editDistance(a, b, m, n - 1), min(editDistance(a, b, m - 1, n), editDistance(a, b, m - 1, n - 1)));
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		int m, n;
		cin >> m >> n;
		cin >> a >> b;
		cout << editDistance(a, b, m, n) << endl;
	}
}