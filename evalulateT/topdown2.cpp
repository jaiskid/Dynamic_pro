#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int evalulate(string s, int i, int j, bool istrue) {
	if (i > j)
		return 0;
	if (i == j) {
		if (istrue == true) {
			return s[i] == 'T';
		}
		else {
			return s[i] == 'F';
		}
	}
	string temp = to_string(i);
	temp.push_back(' ');
	temp.append(to_string(j));
	temp.push_back(' ');
	temp.append(to_string(istrue));
	cout << temp << endl;
	if (mp.find(temp) != mp.end()) {
		return mp[temp];
	}
	int ans = 0;
	for (int k = i + 1; k <= j - 1; k += 2) {
		int lfal = evalulate(s, i, k - 1, false);
		int ltru = evalulate(s, i, k - 1, true);
		int rfal = evalulate(s, k + 1, j, false);
		int rtru = evalulate(s, k + 1, j, true);
		if (s[k] == '&') {
			if (istrue == true) {
				ans = ans + (ltru * rtru);
			} else
				ans = ans + (lfal * rtru) + (ltru * rfal) + (lfal * rfal);
		} else if (s[k] == '|') {
			if (istrue == true) {
				ans = ans + (ltru * rfal) + (rtru * lfal) + (rtru * ltru);
			} else
				ans = ans + (lfal * rfal);
		} else if (s[k] == '^') {
			if (istrue == true)
				ans = ans + (rfal * ltru) + (lfal * rtru);
			else
				ans = ans + (lfal * rfal) + (ltru * rtru);
		}
	}
	return mp[temp] = ans;
}
int main() {
	mp.clear();
	string s;
	cin >> s;
	int n = s.size();
	cout << evalulate(s, 0, n - 1, true);
}