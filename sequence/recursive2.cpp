///2nd approach this is only work for string one match with 2
#include<bits/stdc++.h>
using namespace std;
bool issubsequence(string s, string r, int m, int n) {
	if (m == 0)
		return true;
	if (n == 0)
		return	false;
	if (s[m - 1] == r[n - 1])
		return issubsequence(s, r, m - 1, n - 1);
	return issubsequence(s, r, m, n - 1);
}
int main() {
	string s, r;
	cin >> s >> r;
	int m = s.size();
	int n = r.size();
	issubsequence(s, r, m, n) ? cout << "yes" : cout << "No";
}