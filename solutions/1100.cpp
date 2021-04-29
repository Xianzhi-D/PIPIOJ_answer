#include<bits/stdc++.h>
using namespace std;
char a[23][23];
bool vis[23][23][2];//标记数组
struct node{
    int x,y,t;
}s,e,p;
int dx[] = {0,0,1,0,-1}, dy[] = {0,1,0,-1,0};//方向数组，这么写比较简便
int main(){
    int i,j,m,n;
    while(~scanf("%d%d",&m,&n)){//用~与！=EOF效果一样，写起来方便
        memset(vis,0,sizeof(vis));
        queue<node>q;//bfs肯定得要个队列
        for(i=0;i<m;++i){
            scanf("%s",a[i]);
            for(j=0;j<n;++j){
                if(a[i][j]=='S'){
                    s = {i,j,0};
                    q.push(s);//把起点入队
                    vis[i][j][0] = 1;
                }
                else if(a[i][j]=='T'){
                    e = {i,j,0};
                }
            }
        }
        while(!q.empty()){
            p = q.front();q.pop();
            if(p.x==e.x&&p.y==e.y)break;
            int nt = p.t+1;
            for(i=0;i<5;++i){//遍历各个方向
                int nx = p.x+dx[i], ny = p.y+dy[i];
                if(nx<0||nx>=m||ny<0||ny>=n||a[nx][ny]=='*'||vis[nx][ny][nt&1])continue;
                if(a[nx][ny]!='|'&&a[nx][ny]!='-'){
                    q.push({nx,ny,nt});
                    vis[nx][ny][nt&1] = 1;
                }
                if(i==0)continue;
                if(i&1){//按时间的奇偶性来分类
                    if((p.t%2==1&&a[nx][ny]=='|')||(p.t%2==0&&a[nx][ny]=='-')){
                        nx += dx[i];ny += dy[i];
                        if(nx<0||nx>=m||ny<0||ny>=n||a[nx][ny]=='*'||vis[nx][ny][nt&1])continue;
                        if(a[nx][ny]!='|'&&a[nx][ny]!='-'){
                            q.push({nx,ny,nt});
                            vis[nx][ny][nt&1] = 1;
                        }
                    }
                }
                else{
                    if((p.t%2==0&&a[nx][ny]=='|')||(p.t%2==1&&a[nx][ny]=='-')){
                        nx += dx[i];ny += dy[i];
                        if(nx<0||nx>=m||ny<0||ny>=n||a[nx][ny]=='*'||vis[nx][ny][nt&1])continue;
                        if(a[nx][ny]!='|'&&a[nx][ny]!='-'){
                            q.push({nx,ny,nt});
                            vis[nx][ny][nt&1] = 1;
                        }
                    }
                }
            }
        }
        if(p.x==e.x&&p.y==e.y)printf("%d\n",p.t);
        else printf("-1\n");
    }
    return 0;
}
/*
很显然是搜索题，求最短时间所以用bfs，难点在于楼梯每过一分钟就变动一次方向。
但只要稍微思考一下就知道楼梯是周期变化的，按到达时间的奇偶性分类即可。
而且该题说了地图中不会出现两个相连的梯子，难度也大大降低，接下来就是裸的bfs了。
*/