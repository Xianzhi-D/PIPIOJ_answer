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
�ܼ򵥵���ѧ�⣬�Ͳ��ི�ˣ��ٶ�һ��ѷ�����
ע�����������������ϵͳ�Դ��ĺ��� __gcd(x,y)
*/