#include<bits/stdc++.h>
using namespace std;
int factorial(int n,int *dp)
{
	if(n==0){
	return 1;
	}
	if(dp[n]!=0){
	return dp[n];
	}
	int ans=0;
	ans=n*factorial(n-1,dp);
	return dp[n]=ans;
}
int main(){
	int n;
	cin>>n;
	int dp[10005]={0};
	cout<<factorial(n,dp);
}