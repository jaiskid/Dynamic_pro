#include<bits/stdc++.h>
using namespace std;
int findminsubset(int *arr, int sumCalculate, int n, int range) {
	if (n == 0)
		return abs((range - sumCalculate) - sumCalculate);
	//recursive case
	if (arr[n - 1] <= range)
		return min(findminsubset(arr, sumCalculate + arr[n - 1], n - 1, range), findminsubset(arr, sumCalculate, n - 1, range));
	else if (arr[n - 1] > range)
		findminsubset(arr, sumCalculate, n - 1, range);
}
int minfunction(int *arr, int n) {
	int range = 0;
	for (int i = 0; i < n; i++)
		range += arr[i];
	return findminsubset(arr, 0, n, range);
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << minfunction(arr, n);
}