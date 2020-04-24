#include<bits/stdc++.h>
using namespace std;
//end str means common string end
//result means max length of that length
//enstring - result will give me the initial point
string printsub(string x, string y, int m, int n) {
	int t[m + 1][n + 1];
	int result = 0;
	int endstr;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (x[i - 1] == y[j - 1]) {
				t[i][j] = t[i - 1][j - 1] + 1;
				if (t[i][j] > result) {
					result = t[i][j];
					cout << i << " ";
					endstr = i;
				}

			} else {
				t[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << endstr;
	cout << endl;
	cout << result;
	return x.substr(endstr - result, result);
}
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << printsub(x, y, m, n);
}