#include<bits/stdc++.h>
using namespace std;
int lcs(string s, string r, int m, int n) {
	int t[m + 1][n + 1];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == r[j - 1] and i != j)
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	return t[m][n];
}
int main() {
	string s;
	cin >> s;
	string r;
	r = s;
	int m = s.size();
	int n = r.size();
	cout << lcs(s, r, m, m);
}