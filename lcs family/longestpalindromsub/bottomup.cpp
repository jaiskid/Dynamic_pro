#include<bits/stdc++.h>
using namespace std;
int longestsubstring(string s) {
	int n = s.size();
	//table is false if str[i,j] to  is false
	int table[n][n];
	memset(table, 0, sizeof(table));
	int maxlength = 1;
	for (int i = 0; i < n; i++) {
		table[i][i] = true;
	}
	// check for sub-string of length 2.
	int start = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxlength = 2;
		}
	}
	//check for length greater than 2 k is length of substring
	for (int k = 3; k <= n; k++) {
		for (int i = 0; i < n - k + 1; i++) {
			// Get the ending index of substring from 
            // starting index i and length k 
			int j = i + k - 1;
			if (table[i + 1][j - 1] and s[i] == s[j]) {
				table[i][j] = true;
				if (k > maxlength) {
					start = i;
					maxlength = k;
				}
			}

		}
	}
	cout << s.substr(start, start + maxlength - 1) << endl;
	return maxlength;
}
int main() {
	string s;
	cin >> s;
	cout << longestsubstring(s);
}