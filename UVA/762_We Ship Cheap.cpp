#include "bits/stdc++.h"
using namespace std;

string a, b;
map <string, int> mm;
map <int, string> mp;
map <int, int> pr;
vector <int> v[1510];
int start, finish;
bool visit[1510];
int dist[1510], num[1510];

queue <int> Q;

void BFS(void)
{
    memset(dist, -1, sizeof(dist));
    memset(visit, 0, sizeof(visit));

    while(!Q.empty())
        Q.pop();

    dist[start] = 0;
    visit[start] = 1;
    Q.push(start);

    int u, i, x, p = 0;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            if(visit[v[u][i]] == 0)
            {
                dist[v[u][i]] = dist[u] + 1;
                pr[v[u][i]] = u;
                if(v[u][i] == finish)
                {
                    p = 1;
                    break;
                }
                Q.push(v[u][i]);
                visit[v[u][i]] = 1;
            }
        }
        if(p == 1)
            break;
    }
    return ;
}

int main()
{
    int i, j, n, cnt, x, k = 0;
    while(scanf("%d", &n) == 1)
    {
        ++k;
        if(k > 1)
            printf("\n");
        pr.clear();
        mp.clear();
        mm.clear();
        i = 0;
        for(cnt = 0; cnt < n; ++cnt)
        {
            cin >> a >> b;
            if(mm.find(a) == mm.end())
            {
                mm[a] = ++i;
                mp[i] = a;
            }

            if(mm.find(b) == mm.end())
            {
                mm[b] = ++i;
                mp[i] = b;
            }
            v[mm[a]].push_back(mm[b]);
            v[mm[b]].push_back(mm[a]);
        }
        cin >> a >> b;
        if((mm.find(a) != mm.end()) && (mm.find(b) != mm.end()))
        {
            start = mm[a];
            finish = mm[b];
            BFS();
            if(dist[finish] > -1)
            {
                j = 0;
                num[j] = finish;
                while(pr[num[j]] != start)
                {
                    x = num[j];
                    ++j;
                    num[j] = pr[x];
                }
                x = num[j];
                num[++j] = pr[x];
                a = mp[num[j]];
                for(cnt = j - 1; cnt >= 0; --cnt)
                {
                    b = mp[num[cnt]];
                    cout << a << ' ' << b << endl;
                    a = b;
                }
            }
            else
                printf("No route\n");
        }
        else
            printf("No route\n");
        for(cnt = 0; cnt <= i; ++cnt)
        {
            while(!v[cnt].empty())
                v[cnt].pop_back();
        }
    }
    return 0;
}

/*
3
JV PT
KA PT
KA HP
JV HP
2
JV PT
KA HP
JV HP
*/
