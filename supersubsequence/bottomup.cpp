#include<bits/stdc++.h>
using namespace std;
int supersub(string s, string x, int m, int n) {
	int t[m + 1][n + 1];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == x[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	return t[m][n];
}
int main() {

	string s;
	cin >> s;
	string x;
	cin >> x;
	int m = s.size();
	int n = x.size();
	cout << m + n - supersub(s, x, m, n);

}