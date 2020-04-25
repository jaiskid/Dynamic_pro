#include<bits/stdc++.h>
using namespace std;
int binarysearch(int *arr, int s, int e, int key) {
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] < key)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return -1;
}
int lis(int *arr, int n) {
	int dp[n];
	int len = 0;
	for (int i = 0; i < n; i++) {
		int j = binary_search(dp, dp + len, arr[i]);
		if (j < 0)
			j = -(j + 1);
		dp[j] = arr[i];
		if (j == len)
			len++;

	}
	return len;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << lis(arr, n);
}