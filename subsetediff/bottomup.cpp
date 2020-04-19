#include<bits/stdc++.h>
using namespace std;
int count(int *arr, int sum, int n) {
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return t[n][sum];
}
int main() {
    int n;
    cin >> n;

    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int diff;
    cin >> diff;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int s1 = (diff + sum) / 2;
    cout << count(arr, s1, n);
}