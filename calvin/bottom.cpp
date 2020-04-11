#include<bits/stdc++.h>
using namespace std;

int n,k;

int a[10000000];
int f[10000000],back[10000000];
int maxscore;
int main(){
	cin>>n;
	cin>>k;
	k--;
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	back[0]=0;
	back[1]=a[0];
	for(int i=2;i<n;i++){
	back[i]=max(a[i-2]+back[i-2],a[i-1]+back[i-1]);
	}
	f[k]=0;
	f[k+1]=a[k+1];
	for(int i=k+2;i<n;i++){
	f[i]=a[i]+max(f[i-1],f[i-2]);
	}
	maxscore=back[k]+f[k];
	for(int i=k+1;i<n;i++){
	maxscore=max(maxscore,back[i]+f[i]);
	}
	cout<<maxscore<<endl;
}