#include<bits/stdc++.h>
using namespace std;
int lcsubs(string s, string r, int m, int n, int count) {
	if (m == 0 || n == 0)
		return 0;
	if (s[m - 1] == r[n - 1] and m != n)
		return	 1 + lcsubs(s, r, m - 1, n - 1, count + 1);
	return	count = max(lcsubs(s, r, m - 1, n, 0), lcsubs(s, r, m, n - 1, 0));
}
int main() {
	string s;
	cin >> s;
	string r;
	r = s;
	int m = s.size();
	cout << lcsubs(s, r, m, m, 0);
}