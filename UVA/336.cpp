#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

vector<int> vc[10000],vt;
queue<int > Q,QQ;
bool vis[10000];
int n,e,o,ar[10000];
void bfs(int str)
{
    int m,k,l,i,o;
    memset(vis, 0, sizeof(vis));
    memset(ar, 0, sizeof(ar));
    while(!Q.empty())
        Q.pop();
    Q.push(str);
    ar[str]=0;
    vis[str]=1;
    k=str;
//    printf("0000000000\n");
    while(!Q.empty() && ar[k]<o)
    {
        printf("0000000000\n");
        m=Q.front();
        for(i=0; i<vc[m].size(); i++)
        {
            k=vc[m][i];
            if(vis[k]==0)
            {
                Q.push(k);
                ar[k]=ar[m]+1;
                vis[k]=1;
            }

        }
        Q.pop();
    }
}
int main()
{
    int n,m,j,k,o,i,l;
    while(scanf("%d",&e) && e)
    {
        memset(ar,0,sizeof(ar));
        for(i=1; i<=e; i++)
        {
            scanf("%d%d",&j,&k);
//            ar[j]++;
//            ar[k]++;

            vc[j].push_back(k);
            vc[k].push_back(j);
        }

        while(scanf("%d%d",&o,&l)==2 && (o!=0||l!=0))
        {
            int t=0;
            bfs(o);
            for(i=0; i<1000; i++)
                if(vis[ar[i]]==0 && ar[i]>0)
                    t++;
            printf("Case : %d nodes not reachable from node %d with TTL = %d.\n",t,o,l);
        }
    }
}
/*
16
10 15   15 20   20 25   10 30   30 47   47 50   25 45   45 65
15 35   35 55   20 40   50 55   35 40   55 60   40 60   60 65
35  2   35  3    0  0

14
1 2   2 7   1 3   3 4   3 5   5 10   5 11
4 6   7 6   7 8   7 9   8 9   8  6   6 11
1 1   1 2   3 2   3 3   0 0

0

*/
