#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
bool ispalin(string s, int i, int j) {
	while (i <= j) {
		if (s[i++] != s[j--])
		{
			return false;
		}

	}
	return true;
}

int palindromic(string s, int i, int j) {
	if (i > j)
		return 0;
	if (i == j || ispalin(s, i, j))
		return 0;

	if (t[i][j] != -1)
		return t[i][j];
	int res = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp = palindromic(s, i, k) + 1 + palindromic(s, k + 1, j);
		res = min(res, temp);
	}
	return t[i][j] = res;
}
int main() {
	memset(t, -1, sizeof(t));
	string s;
	cin >> s;

	int n = s.size();
	cout << palindromic(s, 0, n - 1);
}