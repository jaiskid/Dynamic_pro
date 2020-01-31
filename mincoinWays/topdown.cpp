#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int count(int *dp,int n,int sum,int *arr){
	if(sum==0){
	return 1;
	}
	if(sum<0){
	return 0;
	}
	if(n<=0&&sum>=1){
	return 0;
	}
	if(dp[n]!=-1){
	return dp[n];
	}
	int ans=count(dp,n-1,sum,arr)+count(dp,n,sum-arr[n-1],arr);
	return dp[n]=ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int sum;
	cin>>sum;
	int n;
	cin>>n;
	int arr[100005];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	cout<<count(dp,n,sum,arr);

}