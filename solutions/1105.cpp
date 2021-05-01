#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	ll a,b,g,l;
	while(cin>>a>>b){
		g=gcd(a,b);l=a*b/g;
		cout<<g<<" "<<l<<"\n";
	}
	return 0;
}
/*
很简单的数学题，就不多讲了，百度一大堆方法。
注意求最大公因数可以用系统自带的函数 __gcd(x,y)
*/