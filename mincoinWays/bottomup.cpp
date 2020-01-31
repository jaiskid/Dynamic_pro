#include<bits/stdc++.h>
using namespace std;
int count(int *s,int m,int n){
	int table[n+1];
	memset(table,0,sizeof(table));
	table[0]=1;
	for(int i=0;i<m;i++){
	for(int j=s[i];j<=n;j++){
	table[j]+=table[j-s[i]];
	}
	}
	return table [n];
}
int main(){
	int sum;
	cin>>sum;
	int m;
	cin>>m;
	int arr[100005];
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	cout<<count(arr,m,sum);
}