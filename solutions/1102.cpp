#include<bits/stdc++.h>
using namespace std;
int a[20],b[20],r,n,f;
void pr(int k,int x){
    if(k <= 0)return;
    int m, j, i = upper_bound(a,a+x,k)-a;
	--i;
    if(a[i]==k){
        for(j=0;j<r;j++)printf("%d+",b[j]);
        printf("%d\n",k);f=1;
        while(a[i]==k)--i;
    }
    while(i>=0){
    b[r++]=a[i];
    pr(k-a[i],i);
    r--;
    m=a[i];
    while(a[i]==m)--i;
    }
}
int main(){
    int i,t;
    while(~scanf("%d%d",&t,&n)){
        if(t==0&&n==0)break;
        for(i=0;i<n;++i)scanf("%d",&a[i]);
        sort(a,a+n);
		r = 0;
		f = 0;
        printf("Sums of %d:\n",t);
        pr(t,n);
        if(f==0)printf("NONE\n");
    }
    return 0;
}
/*
显然是要用回溯，问题就在于去重，所以排序是必不可少的，找到后要直接跳到下一个不同的数
*/