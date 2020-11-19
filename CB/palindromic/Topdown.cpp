#include<bits/stdc++.h>
using namespace std;
int lookup[1005][1005];

int palindromic(string x, int i, int j) {
	if (i > j) {
		return 0;
	}
	if (i == j)
		return 1;
	if (lookup[i][j] != -1)
		return lookup[i][j];
	if (x[i] == x[j])
		return lookup[i][j] = palindromic(x, i + 1, j - 1) + 2;
	return lookup[i][j] = max(palindromic(x, i + 1, j), palindromic(x, i, j - 1));

}
int main() {
	string x;
	cin >> x;
	int m = x.size();
	memset(lookup, -1, sizeof lookup);
	cout << palindromic(x, 0, m - 1);
}