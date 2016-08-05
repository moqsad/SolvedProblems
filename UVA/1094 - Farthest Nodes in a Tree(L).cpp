#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int position,total,dist[30010];
bool visit[30010];

vector <int>v[30010];
vector<int>cost[30010];

void dfs(int s)
{
    int x,y,i;
    visit[s]=1;
    x=v[s].size();
    for(i=0; i<x; ++i)
    {
        y=v[s][i];
        if(visit[y]==0)
        {
            dist[y]=dist[s]+cost[s][i];
//            printf("%d %d %d____%d\n",s,y,cost[s][i],dist[y]);
            if(dist[y]>total)
            {
                total=dist[y];
                position=y;
            }
            dfs(y);
        }
    }
    return;
}

int main()
{
    int t,cnt,i,n,a,b,c;
    scanf("%d",&t);
    for(cnt=1; cnt<=t; ++cnt)
    {
        scanf("%d",&n);
        for(i=1; i<n; ++i)
        {
            scanf("%d %d %d",&a,&b,&c);
            v[a].push_back(b);
            v[b].push_back(a);

            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        total=0;
        dfs(0);
        memset(visit,0,sizeof(visit));
        memset(dist,0,sizeof(dist));
        dfs(position);
        printf("Case %d: %d\n",cnt,total);
        for(i=0;i<n;++i)
        {
            v[i].clear();
            cost[i].clear();
            visit[i]=0;
            dist[i]=0;
        }
    }
    return 0;
}
