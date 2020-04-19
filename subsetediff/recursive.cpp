#include<bits/stdc++.h>
using namespace std;
int counte_subset(int *arr, int sum, int n) {
	if (sum == 0)
		return 1;
	if (sum != 0 and n == 0)
		return 0;
	if (arr[n - 1] <= sum)
		return counte_subset(arr, sum - arr[n - 1], n - 1) + counte_subset(arr, sum, n - 1);
	if (arr[n - 1] > sum)
		return counte_subset(arr, sum, n - 1);
}
int counter(int *arr, int range, int n, int diff) {
	int s1 = (diff + range) / 2;
	return counte_subset(arr, s1, n);
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int diff;
	cin >> diff;
	int range = 0;
	for (int i = 0; i < n; i++) {
		range += arr[i];
	}
	cout << counter(arr, range, n, diff);
}