#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
bool ismatch(string s, string r) {
	int n = s.size();
	int m = r.size();
	//empty pattern can only match with empty string
	if (m == 0)
		return n == 0;
	//lookup table to storing the result of the subproblem
	bool lookup[n + 1][m + 1];
	//Intialise the table with false
	memset(lookup, false, sizeof lookup);
	//empty pattern can match with empty string
	lookup[0][0] = true;
	for (int j = 1; j <= m; j++) {
		if (r[j - 1] == '*')
			lookup[0][j] = lookup[0][j - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//two cases if we see a "*"
			//a we ignore * character and move to next character in the pattern i.e '*' indicates an empty sequence
			if (r[j - 1] == '*') {
				lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
			}
			else if (r[j - 1] == '?' || (s[i - 1] == r[j - 1])) {
				lookup[i][j] = lookup[i - 1][j - 1];
			}
			else
				//character don't match
				lookup[i][j] = false;
		}
	}
	return lookup[n][m];
}
int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	string r;
	cin >> r;
	cout << ismatch(s, r);
}