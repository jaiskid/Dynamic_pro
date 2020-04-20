#include<bits/stdc++.h>
using namespace std;
int supersubse(string s, string x, int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (s[m - 1] == x[n - 1])
		return supersubse(s, x, m - 1, n - 1) + 1;
	else
		return max(supersubse(s, x, m - 1, n), supersubse(s, x, m, n - 1));
}
int main() {
	string s;
	cin >> s;
	string x;
	cin >> x;
	int m = s.size();
	int n = x.size();
	cout << m + n - supersubse(s, x, m, n);

}