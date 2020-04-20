#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
int longest(string s, int i, int j) {
	if (i > j)
		return 0;
	if (i == j)
		return 1;
	if (t[i][j] != -1)
		return t[i][j];
	if (s[i] == s[j])
		return t[i][j] = longest(s, i + 1, j - 1) + 2;
	return t[i][j] = max(longest(s, i + 1, j), longest(s, i, j - 1));
}
int main() {
	memset(t, -1, sizeof(t));
	string s;
	cin >> s;
	int n = s.size();
	cout << longest(s, 0, n - 1) << endl;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}

}