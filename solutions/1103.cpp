#include<stdio.h>
#include<string.h>
main(){
    char N[10000];//最好是开在全局，堆区内存比栈区大
    long long p,s,n,m[10000];
    int i;
    m[0]=1;
    while(~scanf("%s%lld",&N,&p)){
        s=0; n=strlen(N);
        for(i=1;i<n;i++){
            m[i]=(m[i-1]*10)%p;
            s=(s+m[i]*(N[n-i-1]-'0'))%p;
        }
        s=(s+N[n-1]-'0')%p;
        printf("%lld\n",s);
    }
}
/*
显然这么大的数只能用字符串输入，然后利用取模的性质即可
*/