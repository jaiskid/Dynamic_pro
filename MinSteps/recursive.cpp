#include<bits/stdc++.h>
using namespace std;
int minsteps(int n){
	//base case
	if(n==1){
	return 0;
	}
	//recursive case
	int op1,op2,op3=INT_MAX;
	if(n%2==0){
		op1= minsteps(n/2)+1;
	}
	if(n%3==0){
		op2= minsteps(n/3)+1;
	}
	op3=minsteps(n-1)+1;
	return min(min(op1,op2),op3);

}
int main(){
	int n;
	cin>>n;
	cout<<minsteps(n);

}