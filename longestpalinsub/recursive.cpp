#include<bits/stdc++.h>
using namespace std;
int longest(string x, int i, int j) {
	if (i > j)
		return 0;
	if (i == j)
		return 1;
	if (x[i] == x[j])
		//include first and last element in pallindrome
		return longest(x, i + 1, j - 1) + 2;
	return max(longest(x, i + 1, j), longest(x, i, j - 1));
}
int main() {
	string s;
	cin >> s;
	int n = s.size();
	cout << longest(s, 0, n - 1);
}