#include<bits/stdc++.h>
using namespace std;
int count(int *arr,int n,int sum)
{
	if(sum==0){
	return 1;
	}
	if(sum<0){
	return 0;
	}
	if(n<=0&&sum>=1){
	return 0;
	}
	return count(arr,n-1,sum)+count(arr,n,sum-arr[n-1]);
}
int main(){
	int sum;
	cin>>sum;
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<count(arr,n,sum);

}