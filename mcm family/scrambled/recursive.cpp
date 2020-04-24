#include<bits/stdc++.h>
using namespace std;
bool solve(string s, string r) {
	if (s.compare(r) == 0)
		return true;
	if (s.size() <= 1  || r.size() <= 1)
		return false;
	int n = s.size();
	bool flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((solve(s.substr(0, i), r.substr(n - i, i)) == true and solve(s.substr(i, n - i), r.substr(0, n - i)) == true) || (solve(s.substr(0, i), r.substr(0, i)) == true and solve(s.substr(i, n - i), r.substr(i, n - i)) == true)) {
			flag = true;
			break;
		}

	}
	return flag;
}


int main() {
	string s, r;
	cin >> s >> r;
	int m = s.size();
	int n = r.size();
	if (m != n) {
		cout << 0;
		exit(0);
	}
	if (s.empty() and r.empty()) {
		cout << 1;
		exit(0);
	}
	cout << solve(s, r);
}