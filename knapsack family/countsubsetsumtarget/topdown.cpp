#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
int sumtarget(int *arr, int sum, int n) {
	if (sum == 0)
		return 1;
	if (sum != 0 and n == 0)
		return 0;
	if (t[n][sum] != -1)
		return t[n][sum];
	if (arr[n - 1] <= sum)
		return t[n][sum] = sumtarget(arr, sum - arr[n - 1], n - 1) + sumtarget(arr, sum, n - 1);
	if (arr[n - 1] > sum)
		return t[n][sum] = sumtarget(arr, sum, n - 1);
}
int main() {
	memset(t, -1, sizeof(t));
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum;
	cin >> sum;
	cout << sumtarget(arr, sum, n);
}