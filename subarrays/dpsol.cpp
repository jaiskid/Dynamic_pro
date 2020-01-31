#include<bits/stdc++.h>
using namespace std;
int maximum(int *arr,int n){
	int dp[1000]={0};
	int max_so_far=0;
	dp[0]=arr[0]>0?arr[0]:0;
	for(int i=1;i<=n;i++){
		dp[i]+=dp[i-1]+arr[i];
		if(dp[i]<0){
		dp[i]=0;
		}
		max_so_far=max(max_so_far,dp[i]);
	}
	return max_so_far;
}
int main(){
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	cout<<maximum(arr,n);
}