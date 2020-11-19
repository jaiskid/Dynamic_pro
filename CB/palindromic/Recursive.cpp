//Time O(2^n)
#include<bits/stdc++.h>
using namespace std;
int palindromic(string x, int i, int j) {
	if (i > j)
		return 0;
	if (i == j)
		return 1;
	if (x[i] == x[j])
		return palindromic(x, i + 1, j - 1) + 2;
	return max(palindromic(x, i + 1, j), palindromic(x, i, j - 1));
}
int main() {
	string x;
	cin >> x;
	int m = x.size();
	cout << palindromic(x, 0, m - 1);

}