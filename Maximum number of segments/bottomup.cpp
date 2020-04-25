#include<bits/stdc++.h>
using namespace std;
int maximisegment(int n, int a, int b, int c) {
	int t[n + 1];
	memset(t, -1, sizeof(t));
	t[0] = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] != -1) {
			if (i + a <= n) {
				t[i + a] = max(t[i + a], t[i] + 1);
			}
			if (i + b <= n) {
				t[i + b] = max(t[i + b], t[i] + 1);
			}
			if (i + c <= n) {
				t[i + c] = max(t[i + c], t[i] + 1);
			}
		}
	}
	return t[n];
}
int main() {
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	cout << maximisegment(n, a, b, c);
}