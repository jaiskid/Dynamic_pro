#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001]; // n * sum
bool subset(int *arr, int sum, int n) {
	if (sum == 0)
		return true;
	if (sum != 0 and n == 0)
		return false;
	if (t[n][sum] != -1)
		return t[n][sum];
	if (arr[n - 1] <= sum)
		return t[n][sum] = subset(arr, sum - arr[n - 1], n - 1) || subset(arr, sum, n - 1);
	if (arr[n - 1] > sum)
		return t[n][sum] = subset(arr, sum, n - 1);

}
int main() {
	memset(t, -1, sizeof(t));
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum;
	cin >> sum;
	cout << subset(arr, sum, n);

}