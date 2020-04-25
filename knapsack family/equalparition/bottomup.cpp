#include <iostream>
#include <string>
using namespace std;

// Return true if there exists a subset of array[0..n) with given sum
bool subsetSum(int arr[], int n, int sum)
{
	// T[i][j] stores true if subset with sum j can be attained with
	// using items up to first i items
	bool T[n + 1][sum + 1];

	// if 0 items in the list and sum is non-zero
	for (int j = 0; j < sum + 1; j++) {
		// if sum is zero
		for (int i = 0; i < n + 1; i++) {
			if (i == 0)
				T[i][j] = false;
			if (j == 0)
				T[i][j] = true;
		}
	}





	// do for ith item
	for (int i = 1; i < n + 1; i++)
	{
		// consider all sum from 1 to sum
		for (int j = 1; j < sum + 1; j++)
		{
			// don't include ith element if j-arr[i-1] is negative
			if (arr[i - 1] > j)
				T[i][j] = T[i - 1][j];
			else
				// find subset with sum j by excluding or including the ith item
				T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
		}
	}

	// return maximum value
	return T[n][sum];
}

// Partition problem - Return true if given array arr[0..n-1] can
// be divided into two subsets with equal sum
bool partition(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// return true if sum is even and array can can be divided into
	// two subsets with equal sum
	return !(sum & 1) && subsetSum(arr, n, sum / 2);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		(partition(arr, n) == 1) ? cout << "YES" << endl : cout << "NO" << endl;
	}


}