#include<bits/stdc++.h>
using namespace std;
int minCoins(int n,int *coins,int t,int *dp)
{
	if(n==0){
	return 0;
	}
	if(dp[n]!=0){
	return dp[n];
	}
	int ans=INT_MAX;
	for(int i=0;i<t;i++){
	if(n-coins[i]>=0){
	int subprob=minCoins(n-coins[i],coins,t,dp);
		
		ans=min(ans,subprob+1);
	}
	}
	dp[n]=ans;
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	int t;
	cin>>t;
	int coins[10005];
	for(int i=0;i<t;i++){
		cin>>coins[i];
	}
	int dp[10005]={0};
	cout<<minCoins(n,coins,t,dp);
}