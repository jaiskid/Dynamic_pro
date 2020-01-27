#include<bits/stdc++.h>
using namespace std;
int wines(int *bottle,int i,int j,int y){
	if(i>j){
	return 0;
	}
	int ans=INT_MIN;
	ans=max(bottle[i]*y+wines(bottle,i+1,j,y+1),bottle[j]*y+wines(bottle,i,j-1,y+1));
	return ans;
}
int main(){
	int n;
	cin>>n;
	int bottle[10005];
	for(int i=0;i<n;i++){
	cin>>bottle[i];
	}
	cout<<wines(bottle,0,n,0);
}