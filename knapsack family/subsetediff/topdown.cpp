#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int count(int *arr, int sum, int n) {
	if (sum == 0)
		return 1;
	if (sum != 0 and n == 0)
		return 0;
	if (t[n][sum] != -1)
		return t[n][sum];
	if (arr[n - 1] <= sum)
		return t[n][sum] = count(arr, sum - arr[n - 1], n - 1) + count(arr, sum, n - 1);
	if (arr[n - 1] > sum)
		return t[n][sum] = count(arr, sum, n - 1);

}
int main() {
	memset(t, -1, sizeof(t));
	int n;
	cin >> n;
	int arr[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int diff;
	cin >> diff;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	int s1 = (diff + sum) / 2;
	cout << count(arr, s1, n);
}