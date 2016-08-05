#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector <int> g1[50];
vector <int> g2[50];

stack <int> S;
map <string, int> mm;
map <int, string> nn;
string arr;

bool taken[50];
char a[50], b[50];
int k, num[50];

void dfs1(int p)
{
    int i, x;
    if(!taken[p])
    {
        taken[p] = 1;
        x = g1[p].size();
        for(i = 0; i < x; ++i)
            dfs1(g1[p][i]);
        S.push(p);
    }
}

void dfs2(int p)
{
    int i, x;
    if(!taken[p])
    {
        taken[p] = 1;
        num[k++] = p;
        x = g2[p].size();
        for(i = 0; i < x; ++i)
            dfs2(g2[p][i]);
    }
}

int main()
{
    int n, m, x, y, i, j, cnt = 0;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        if(++cnt > 1)
            printf("\n");
        mm.clear();
        nn.clear();
        j = 0;
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s", a, b);
            if(mm.find(a) == mm.end())
            {
                mm[a] = ++j;
                arr = a;
                nn[j] = arr;
            }
            if(mm.find(b) == mm.end())
            {
                mm[b] = ++j;
                arr = b;
                nn[j] = arr;
            }
            g1[mm[a]].push_back(mm[b]);
            g2[mm[b]].push_back(mm[a]);
        }
        for(i = 1; i <= n; ++i)
            dfs1(i);
        memset(taken, 0, sizeof(taken));
        printf("Calling circles for data set %d:\n", cnt);
        k = 0;
        while(!S.empty())
        {
            if(!taken[S.top()])
            {
                dfs2(S.top());
                cout << nn[num[0]];
                for(j = 1; j < k; ++j)
                    cout << ", " << nn[num[j]];
                printf("\n");
                k = 0;
            }
//            printf("%d______\n", S.top());
            S.pop();
        }
        memset(taken, 0, sizeof(taken));
        for(i = 1; i <= n; ++i)
        {
            g1[i].clear();
            g2[i].clear();
        }
    }
    return 0;
}

/*
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron
*/
