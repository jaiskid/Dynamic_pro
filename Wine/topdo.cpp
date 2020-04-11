#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int NN = 1000;
#define INF 999999

int dp[1000][1000] = {0}, price[] = {2, 3, 5, 1, 4};;

int maxPrice(int start, int end, int N) {

	//If we have solved this sub-problem, return the memoized answer
	if (dp[start][end] != 0)
		return dp[start][end];

	//base case
	if (start > end)
		return 0;

	//To get the current year
	int year = N - (end - start + 1) + 1;
	//Including the starting index
	int incStart = year * price[start] + maxPrice(start + 1, end, N);

	//Including the ending index
	int incEnd = year * price[end] + maxPrice(start, end - 1, N);

	//memoize this solution and return
	return dp[start][end] = max(incStart, incEnd);

}

int main() {
	int n;
	n = sizeof(price) / sizeof(price[0]);
	cout << n;
	cout << maxPrice(0, n - 1, n - 1);

}