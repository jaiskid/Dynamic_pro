#include<bits/stdc++.h>
using namespace std;
int repeat(string s, string r, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (s[m - 1] == r[n - 1] and m != n)
		return 1 + repeat(s, r, m - 1, n - 1);
	return max(repeat(s, r, m - 1, n), repeat(s, r, m, n - 1));
}
int main() {
	string s;
	cin >> s;
	string  r = s;
	int m = s.size();
	cout << repeat(s, r, m, m);
}