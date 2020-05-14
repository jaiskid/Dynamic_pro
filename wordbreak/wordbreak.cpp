#include<bits/stdc++.h>
using namespace std;
unordered_map<string , bool> h;
int *dp;
int  solve(string s, int pos) {
	//base case
	if (pos == s.length()) {
		return 1;
	}
	if (dp[pos] != -1)
		return dp[pos];
	for (int end = pos + 1; end <= s.length(); end++) {
		string x = s.substr(pos, end - pos);
		if (h.count(x) and solve(s, end)) {
			return dp[pos] = 1;
		}
	}
	return dp[pos] = 0;
}
bool wordbreak(string s, vector<string>& wordDict) {
	for (int i = 0; i < wordDict.size(); i++) {
		h.insert({wordDict[i], true});
	}
	dp = new int[s.length() + 1];
	for (int i = 0; i <= s.length(); i++)
		dp[i] = -1;
	return solve(s, 0);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	vector<string>S;
	int n;
	cin >> n;
	S.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	cout << S[4] << " ";
	cout << wordbreak(s, S);
}
