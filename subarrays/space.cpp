#include<bits/stdc++.h>
using namespace std;
int maximum(int *arr,int n){
	int current_s=0;
	int max_s=0;
	for(int i=0;i<n;i++){
	current_s+=arr[i];
	if(current_s<0){
	current_s=0;
	}
	max_s=max(current_s,max_s);
	}
	return max_s;
}
int main()
{
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	cout<<maximum(arr,n);
}