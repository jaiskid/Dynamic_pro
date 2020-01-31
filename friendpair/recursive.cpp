#include<iostream>
using namespace std;
int countpair(int n){
	if(n<=2){
	return n;
	}
	int ans=countpair(n-1)+(n-1)*countpair(n-2);
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<countpair(n);
}