#include<iostream>
using namespace std;
int catlan(int n){
	unsigned long int cn[10005];
	cn[0]=cn[1]=1;
	for(int i=2;i<=n;i++){
		cn[i]=0;
	for(int j=0;j<i;j++)
	{
		cn[i]+=cn[j]*cn[i-j-1];
	}
	} 
	return cn[n];
}
int main(){
	int n;
	cin>>n;
	cout<<catlan(n);
}