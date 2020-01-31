#include<iostream>
using namespace std;
int catlan(int n){
	if(n<=1){
	return 1;
	}
	int ans=0;
	for(int i=0;i<n;i++){
	ans+=catlan(i)*catlan(n-i-1);
	}
	return ans;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cout<<catlan(i)<<" ";
	}
	
}