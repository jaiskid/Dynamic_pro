#include<bits/stdc++.h>
using namespace std;
int bottomUp(int N,int *coins,int t){
  int dp[10005];
  for(int n=1;n<=N;n++){
  dp[n]=INT_MAX;
  for(int i=0;i<t;i++){
  if(n-coins[i]>=0){
  int subprob=dp[n-coins[i]];
  dp[n]=min(dp[n],subprob+1);
  }
  }
  }
  return dp[N];
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
    cout<<bottomUp(n,coins,t);
}