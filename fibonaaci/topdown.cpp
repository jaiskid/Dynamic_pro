#include<iostream>
using namespace std;
int fibo(int n,int *dp){
	int ans;
	//base case
	if(n==0||n==1){
	return n;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	//recursive case
	ans=fibo(n-1,dp)+fibo(n-2,dp);
	return dp[n]=ans;
}
int main(){
	int dp[1000]={0};

	int n;
	cin>>n;
	cout<<fibo(n,dp);
}