#include<bits/stdc++.h>
using namespace std;
bool subset(int *arr, int sum, int n)
{
	if (sum == 0 )
		return true;
	if (n == 0 and sum != 0)
		return false;
	if (arr[n - 1] <= sum)
		return  subset(arr, sum - arr[n - 1], n - 1) || subset(arr, sum, n - 1);
	if (arr[n - 1] > sum)
		return subset(arr, sum, n - 1);
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum;
	cin >> sum;
	cout << subset(arr, sum, n);
}