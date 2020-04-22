#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s, int i, int j) {
	while (i <= j) {
		if (s[i++] != s[j--])
			return false;
	}
	return true;
}
int solve(string s, int i, int j) {
	if (i > j)
		return 0;
	if (i == j || ispalindrome(s, i, j))
		return 0;
	int res = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp = solve(s, i, k) + 1 + solve(s, k + 1, j);
		res = min(res, temp);
	}
	return res;
}
int main() {
	string s;
	cin >> s;
	int n = s.size();
	cout << solve(s, 0, n - 1);
}