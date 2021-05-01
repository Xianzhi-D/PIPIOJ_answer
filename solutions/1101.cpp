#include<bits/stdc++.h>
using namespace std;
char a[103][103];
int vis[103][103],flag;
struct node{
    int x,y,t;
}s,e,p[2];
int dx[] = {0,1,0,-1,1,1,-1,-1}, dy[] = {1,0,-1,0,1,-1,1,-1},m,n;
queue<node>q[2];
bool bfs(int w){//w为0代表人，w为1代表火
    int i,k=q[w].size(),j=(w?8:4);
    while(k--){
        p[w] = q[w].front();
        if(p[0].x==e.x&&p[0].y==e.y)return flag=1;
        q[w].pop();
        for(i=0;i<j;++i){
            int nx = p[w].x+dx[i], ny = p[w].y+dy[i];
            if(nx<0||nx>=m||ny<0||ny>=n||(w==0&&vis[nx][ny])||(w==1&&vis[nx][ny]==2))continue;
            q[w].push({nx,ny,p[w].t+1});
            vis[nx][ny] = 1+w;
        }
    }
    return 0;
}
int main(){
    int i,j,k;
    while(~scanf("%d%d%d",&m,&n,&k)){
        if(n==0&&m==0&&k==0)break;
        memset(vis,0,sizeof(vis));
        flag = 0;
        for(i=0;i<2;++i){while(!q[i].empty())q[i].pop();}
        for(i=0;i<m;++i){
            scanf("%s",a[i]);
            for(j=0;j<n;++j){
                if(a[i][j]=='s'){
                    s = {i,j,0};
                    q[0].push(s);
                    vis[i][j] = 1;
                }
                else if(a[i][j]=='t'){
                    e = {i,j,0};
                }
                else if(a[i][j]=='f'){
                    vis[i][j] = 2;
                    q[1].push({i,j,0});
                }
            }
        }
        j = 1;
        while(!q[0].empty()||!q[1].empty()){
            if(j%k==0)bfs(1);
            j++;
            if(bfs(0))break;
        }
        if(flag)printf("%d\n",p[0].t);
        else printf("Impossible\n");
    }
    return 0;
}
/*
模拟加bfs，按照时间让火和人同时bfs
*/