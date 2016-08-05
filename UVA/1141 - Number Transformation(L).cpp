#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

vector<int>v[1005];
bool visit[1005];
int dist[1005];

void sieve()
{
    int i,j;
    for(i=2; i<=500; ++i)
    {
        if(v[i].empty())
            for(j=i+i; j<=1000; j+=i)
            {
                v[j].push_back(i);
            }
    }
}

int bfs(int s,int f)
{
    if(s==f)
        return 0;
    memset(dist,-1,sizeof(dist));
    memset(visit,0,sizeof(visit));
    queue<int>Q;
    Q.push(s);
    dist[s]=0;
    int i,x,u,p=0,y;
    while(!Q.empty())
    {
        u=Q.front();
//        for(i=0; i<v[u].size(); i++)
//            printf("%d__\n",v[u][i]);
        Q.pop();
        x=v[u].size();
        for(i=0; i<x; ++i)
        {
            y=u+v[u][i];
            if(visit[y]==0 && y<=f)
            {
                dist[y]=dist[u]+1;
                if(y==f)
                    return dist[y];
                Q.push(y);
                visit[y]=1;
            }
        }
    }
    return dist[f];
}

int main()
{
    int t,cnt,s,f,ans;
    sieve();
    scanf("%d", &t);
    for(cnt=1; cnt<=t; ++cnt)
    {
        scanf("%d %d",&s,&f);
        ans=bfs(s,f);
        if(ans>=0)
            printf("Case %d: %d\n",cnt,ans);
        else
            printf("Case %d: -1\n",cnt);
    }
    return 0;
}
