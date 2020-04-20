#include<bits/stdc++.h>
using namespace std;
string palsubstring(string s, string r, int m, int n) {
	int t[m + 1][n + 1];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	int result = 0;
	int end = m;
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == r[j - 1]) {
				t[i][j] = t[i - 1][j - 1] + 1;
				if (result < t[i][j]) {
					result = t[i][j];
					end = i;
				}
			}
			else t[i][j] = 0;
		}
	}
	return s.substr(end - result, result);
}
int main() {
	string s;
	cin >> s;
	string r;
	r = s;
	reverse(r.begin(), r.end());
	int m = s.size();
	int n = r.size();
	cout << palsubstring(s, r, m, n);
}