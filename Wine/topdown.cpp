#include<bits/stdc++.h>
using namespace std;
int profit(int *wines,int dp[][1005],int i,int j,int y){
	if(i>j){
	return 0;
	}
	if(dp[i][j]!=0){
	return dp[i][j];
	}
	int ans=max(wines[i]*y+profit(wines,dp,i+1,j,y+1),wines[j]*y+profit(wines,dp,i,j-1,y+1));
	dp[i][j]=ans;
	return dp[i][j];
}
int main(){
	int n;
	cin>>n;
	int wines[10005];
	int dp[1005][1005]={0};
	for(int i=0;i<n;i++){
	cin>>wines[i];
	}
	cout<<profit(wines,dp,0,n,0);
}