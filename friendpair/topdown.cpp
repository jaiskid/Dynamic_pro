#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll dp[10005];
ll int countpair(ll int n,ll int *dp){
	if(dp[n]!=-1){
	return dp[n];
	}
	if(n>2){
	return dp[n]=countpair(n-1,dp)+(n-1)*countpair(n-2,dp);
	}
	else{
	return dp[n]=n;
	}
}
int main(){
	memset(dp, -1, sizeof(dp));
	int n;
	cin>>n;
	cout<<countpair(n,dp)<<endl;
}