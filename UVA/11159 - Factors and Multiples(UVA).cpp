#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

bool visit[105];
int match[105], A[105];

vector <int> edge[105];

bool bpm(int s)
{
    int i, x, y;

    x = edge[s].size();

    for(i = 0; i < x; ++i)
    {
        y = edge[s][i];
        if(visit[y] == 0)
        {
            visit[y] = 1;
            if(match[y] == -1 || bpm(match[y]))
            {
                match[y] = s;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t, cnt, n, m, bad, i, j, b;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        bad = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%d", &A[i]);

        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d", &b);
            for(j = 0; j < n; ++j)
            {
                if((A[j] == 0 && b == 0) || (A[j] != 0 && b % A[j] == 0)) //special case.......
                    edge[j].push_back(i);
            }
        }

        memset(match, -1, sizeof(match));
        for(i = 0; i < n; ++i)
        {
            memset(visit, 0, sizeof(visit));
            if(bpm(i))
                ++bad;
        }

        printf("Case %d: %d\n", cnt, bad);

        for(i = 0; i < n; ++i)
        edge[i].clear();
    }
    return 0;
}
