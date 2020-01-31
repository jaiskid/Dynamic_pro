#include<bits/stdc++.h>
using namespace std;
int maxProfit(int *bottle,int n){
	int dp[100][100]={};
	int year=n;
	//diagonal conditions
	for(int i=0;i<n;i++){
		dp[i][i]=bottle[i]*year;
	}
	--year;
	for(int len=2;len<=n;++len){
	int srt=0;
	int end=n-len;
	while(srt<=end){
		int endWindow=srt+len-1;
		dp[srt][endWindow]=max(bottle[srt]*year+dp[srt+1][endWindow],bottle[endWindow]*year+dp[srt][endWindow-1]);
		++srt;
	}
	--year;
	}
	for(int i=0;i<n;++i){
	for(int j=0;j<n;++j){
	cout<<setw(3)<<dp[i][j]<<" ";
	}
	cout<<endl;
	}
	return dp[0][n-1];
}
int main(){
	int n;
	cin>>n;
	int bottle[10005];
	for(int i=0;i<n;i++){
	cin>>bottle[i];
	}
	cout<<maxProfit(bottle,n);
}