#include<stdio.h>
#include<string.h>
main(){
    char N[10000];//����ǿ���ȫ�֣������ڴ��ջ����
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
��Ȼ��ô�����ֻ�����ַ������룬Ȼ������ȡģ�����ʼ���
*/