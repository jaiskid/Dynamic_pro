#include<bits/stdc++.h>
using namespace std;
int lcs(string s, string r, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (s[m - 1] == r[n - 1])
		return 1 + lcs(s, r, m - 1, n - 1);
	return max(lcs(s, r, m - 1, n), lcs(s, r, m, n - 1));
}
int main() {
	string s, r;
	cin >> s >> r;
	int m = s.size();
	int n = r.size();
	(lcs(s, r, m, n) == min(m, n)) ? cout << 1 : cout << 0;
}