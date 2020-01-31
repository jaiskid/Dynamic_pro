#include<bits/stdc++.h>
using namespace std;
int ladder_rec(int n,int k){
	if(n==0){
	return 1;
	}
	int ways=0;
	for(int i=1;i<=k;i++){
			if(n-i>=0)
			ways+=ladder_rec(n-i,k);
	}
	return ways;			
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<ladder_rec(n,k);
}