#include<bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool solve(string a, string b) {
	if (a.compare(b) == 0)
		return true;
	if (a.size() <= 1 || b.size() <= 1)
		return false;
	string key = a;
	key.push_back(' ');
	key.append(b);
	if (mp.find(key) != mp.end()) {
		return mp[key];
	}

	bool flag = false;
	int n = a.size();
	for (int i = 1; i <= n - 1; i++) {
		//case 1 phela wala and second last wala and last wala and second ka  phela wala
		//case 2 phela wala and second ka phele wala  and phele wale ka last wala second wale ke last ke sath
		if ((solve(a.substr(0, i), b.substr(n - i, i)) == true and solve(a.substr(i, n - i), b.substr(0, n - i)) == true) || (solve(a.substr(0, i), b.substr(0, i)) == true and solve(a.substr(i, n - i), b.substr(i, n - i)) == true)) {
			return flag = true;
			break;
		}
	}

	return mp[key] = flag;
}
int main() {
	mp.clear();
	string a, b;
	cin >> a >> b;
	int m = a.size();
	int n = b.size();
	
	if (m != n) {
		cout << 0;
		exit(0);
	}
	if (a.empty() || b.empty()) {
		cout << 1;
		exit(1);
	}
	cout << solve(a, b);
}