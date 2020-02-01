#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
	int dp[1000]={0};
	dp[0]=1;
	for(int i=1;i<=n;i++){
	dp[i]=i*dp[i-1];
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	cout<<factorial(n);
}