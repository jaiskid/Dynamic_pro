#include<iostream>
using namespace std;
int catlan(int n,int *dp){
	if(n<=1){
	return 1;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	int ans=0;
	for(int i=0;i<n;i++){
	ans+=catlan(i,dp)*catlan(n-i-1,dp);
	}
	return dp[n]=ans;
}
int main(){
	int n;cin>>n; 
	int dp[10005]={};
	cout<<catlan(n,dp);
	
}