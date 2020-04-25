#include<bits/stdc++.h>
using namespace std;
int maXSumLis(int *arr,int n){
	int msis[n];
	for(int i=0;i<n;i++)
		msis[i]=arr[i];
	for(int i=1;i<n;i++){
		
		for(int j=0;j<i;j++){

			if(arr[i]>arr[j] and msis[i]<msis[j]+arr[i])
			msis[i]=msis[j]+arr[i];
		}
	}
	return *max_element(msis,msis+n);
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maXSumLis(arr,n);

}