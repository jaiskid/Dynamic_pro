#include<bits/stdc++.h>
using namespace std;
int editDistance(string a, string b, int m, int n) {
	int t[m + 1][n + 1];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++ ) {
			if (i == 0)
				t[i][j] = j;
			if (j == 0)
				t[i][j] = i;

		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (a[i - 1] == b[j - 1])
				t[i][j] = t[i - 1][j - 1];
			else
				//t[i][j-1] insert
				//t[i-1][j] remove
				//t[i-1][j-1] replace
				t[i][j] = 1 + min(t[i][j - 1], min(t[i - 1][j], t[i - 1][j - 1]));
		}
	}
	return t[m][n];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		string a, b;
		cin >> a >> b;
		cout << editDistance(a, b, m, n) << endl;
	}
}




