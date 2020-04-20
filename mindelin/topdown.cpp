#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
int lcs(string s, string r, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (t[m][n] != -1)
		return t[m][n];
	if (s[m - 1] == r[n - 1])
		return t[m][n] = 1 + lcs(s, r, m - 1, n - 1);
	else
		return t[m][n] = max(lcs(s, r, m - 1, n), lcs(s, r, m, n - 1));
}
int main() {
	memset(t, -1, sizeof(t));
	string s, r;
	cin >> s >> r;
	int m = s.size();
	int n = r.size();
	int res = lcs(s, r, m, n);
	cout << m - res;
	cout << endl;
	cout << n - res;
}