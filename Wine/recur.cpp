#include<bits/stdc++.h>
using namespace std;
int wine(int *prices, int start, int end, int year) {
	if (start > end) {

		return 0;
	}
	int incstart = prices[start] * year + wine(prices, start + 1, end, year + 1);
	int incend = prices[end] * year + wine(prices, start, end - 1, year + 1);
	return max(incstart, incend);
}
int main() {
	int n;
	cin >> n;
	int prices[10005];
	for (int i = 0; i < n; i++)
		cin >> prices[i];

	cout << wine(prices, 0, n - 1, 1);
}