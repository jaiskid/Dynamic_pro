#include<bits/stdc++.h>
using namespace std;
int maxDivide(int a, int b) {
	while (a % b == 0) {
		a /= b;
	}
	return a;
}
int isugly(int n) {
	n = maxDivide(n, 2);
	n = maxDivide(n, 3);
	n = maxDivide(n, 5);
	return (n == 1) ? 1 : 0;
}
int nthugly(int n) {
	int i = 1;
	int count = 1;
	while (n > count) {
		i++;
		if (isugly(i))
			count++;
	}
	return i;
}
int main() {
	int n;
	cin >> n;
	cout << nthugly(n);
}