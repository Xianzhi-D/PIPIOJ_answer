#include<bits/stdc++.h>
using namespace std;
char a[23][23];
bool vis[23][23][2];//�������
struct node{
    int x,y,t;
}s,e,p;
int dx[] = {0,0,1,0,-1}, dy[] = {0,1,0,-1,0};//�������飬��ôд�Ƚϼ��
int main(){
    int i,j,m,n;
    while(~scanf("%d%d",&m,&n)){//��~�룡=EOFЧ��һ����д��������
        memset(vis,0,sizeof(vis));
        queue<node>q;//bfs�϶���Ҫ������
        for(i=0;i<m;++i){
            scanf("%s",a[i]);
            for(j=0;j<n;++j){
                if(a[i][j]=='S'){
                    s = {i,j,0};
                    q.push(s);//��������
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
            for(i=0;i<5;++i){//������������
                int nx = p.x+dx[i], ny = p.y+dy[i];
                if(nx<0||nx>=m||ny<0||ny>=n||a[nx][ny]=='*'||vis[nx][ny][nt&1])continue;
                if(a[nx][ny]!='|'&&a[nx][ny]!='-'){
                    q.push({nx,ny,nt});
                    vis[nx][ny][nt&1] = 1;
                }
                if(i==0)continue;
                if(i&1){//��ʱ�����ż��������
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
����Ȼ�������⣬�����ʱ��������bfs���ѵ�����¥��ÿ��һ���Ӿͱ䶯һ�η���
��ֻҪ��΢˼��һ�¾�֪��¥�������ڱ仯�ģ�������ʱ�����ż�Է��༴�ɡ�
���Ҹ���˵�˵�ͼ�в�������������������ӣ��Ѷ�Ҳ��󽵵ͣ��������������bfs�ˡ�
*/