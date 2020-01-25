#include<bits/stdc++.h>
using namespace std;
int MinStep(int n){
	int dp[1000]={0};
	
	for(int i=2;i<=n;i++){
		int op1,op2,op3;
	 op1=op2=op3=INT_MAX;
	if(n%2==0){
	op1=dp[i/2];
	}
	if(n%3==0){
	op2=dp[i/3];
	}
	op3=dp[i-1];
	dp[i]=min(min(op1,op2),op3)+1;
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	cout<<MinStep(n);
}