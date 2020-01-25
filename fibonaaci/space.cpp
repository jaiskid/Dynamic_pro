#include<iostream>
using namespace std;
int fib(int n){

	int a=0,b=1;
	int sum=0;
	for(int i=2;i<=n;i++){
	
	sum=a+b;
	
	a=b;
	b=sum;
	}
	return sum;
}
int main(){
int n;
	cin>>n;
	cout<<fib(n);

}