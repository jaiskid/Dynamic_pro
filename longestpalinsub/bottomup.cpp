#include<bits/stdc++.h>
using namespace std;
string lcs(string s, string r, int m, int n) {
	int t[m + 1][n + 1];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == r[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];

			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	int i = m;
	int j = n;
	string ans = "";
	while (i > 0 and j > 0) {
		if (s[i - 1] == r[j - 1]) {
			//ans.push_back(s[i - 1]);
			ans = s[i - 1] + ans;
			i--;
			j--;
		}
		else {
			if (t[i][j - 1] > t[i - 1][j]) {
				j--;
			}
			else {
				i--;
			}
		}

	}
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << t[i][j] << " ";

		}
		cout << endl;
	}
	//return t[m][n];
	return ans;
}

int main() {
	string s;
	cin >> s;
	int m = s.size();
	string r = s;
	reverse(r.begin(), r.end());
	int n = r.size();
	cout << lcs(s, r, m, n);
}