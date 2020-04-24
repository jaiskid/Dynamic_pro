#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001][2];
int evalulate(string s, int i, int j, bool istrue) {
	if (i > j)
		return 0;
	if (i == j) {
		if (istrue == true)
			return s[i] == 'T';
		else
			return s[i] == 'F';
	}
	if (t[i][j][istrue] != -1)
		return t[i][j][istrue];
	int ans = 0;
	for (int k = i + 1; k <= j - 1; k += 2) {
		int lf = evalulate(s, i, k - 1, false);
		int lt = evalulate(s, i, k - 1, true);
		int rf = evalulate(s, k + 1, j, false);
		int rt = evalulate(s, k + 1, j, true);
		if (s[k] == '&') {
			if (istrue == true)
				ans = ans + lt * rt;
			else
				ans = ans + lf * rt + rf * lt + lf * rf;
		} else if (s[k] == '|') {
			if (istrue == true) {
				ans = ans + lt * rt + lt * rf + lf * rt;
			} else
				ans = ans + lf * rf;
		}
		else if (s[k] == '^') {
			if (istrue == true) {
				ans = ans + lf * rt + lt * rf;
			} else
				ans = ans + lt * rt + lf * rf;
		}
	}
	for (int ii = 0; ii < i; ii++) {
		for (int jj = 0; jj < j; jj++) {
			for (int kk = 0; kk < istrue; kk++) {
				cout << t[ii][jj][kk] << " ";
			}
		}
		cout << endl;
	}
	return t[i][j][istrue] = ans;
}
int main() {
	memset(t, -1, sizeof(t));
	string s;
	cin >> s;
	int m = s.size();
	cout << evalulate(s, 0, m - 1, true);
}