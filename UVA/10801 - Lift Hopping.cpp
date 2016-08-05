#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

int visit[10][110], t[10], d[10][110], color[10][110], n, num[10];
char arr[1000];

struct data
{
    int elevator, dist, floor;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

priority_queue <data> q;

int difference(int a, int b)
{
    if(a > b)
        return a - b;
    else
        return b - a;
}

void dijkstra(int start)
{
    d[start][0] = 0;
    data u, v;
    u.elevator = start;
    u.floor = 0;
    u.dist = 0;
    q.push(u);

    int i, j, x, y, z;
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        x = u.elevator;
        for(i = 0; i < num[x]; ++i)
        {
            y = visit[x][i];
            z = u.dist + difference(y, u.floor) * t[x];
//            printf("%d %d___________\n", u.dist, z);
            if(z < d[x][y])
            {
                d[x][y] = z;
                z = z + 60;
                for(j = 0; j < n; ++j)
                {
                    if(color[j][y] == 1 && d[j][y] > z)
                    {
//                        printf("%d %d___++++++++++%d___%d\n", j, y, d[x][y], z);
                        v.elevator = j;
                        v.floor = y;
                        v.dist = z;
                        q.push(v);
                        d[j][y] = z;
                    }
                }
            }
        }
    }
}

int main()
{
    int k, i, j, a, total;
    while(scanf("%d %d\n", &n, &k) == 2)
    {
        for(i = 0; i < n; ++i)
        {
            scanf("%d\n", &t[i]);
            for(j = 0; j < 100; ++j)
            {
                d[i][j] = 1000000000;
            }
        }

        memset(color, 0, sizeof(color));

        for(i = 0; i < n; ++i)
        {
            j = 0;
            gets(arr);
            stringstream sin (arr);
            while(sin >> a)
            {
                visit[i][j] = a;
                color[i][a] = 1;
                ++j;
            }
            num[i] = j;
        }

        for(i = 0; i < n; ++i)
        {
            if(visit[i][0] == 0)
            {
                dijkstra(i);
            }
        }

        total = 1000000000;
        for(i = 0; i < n; ++i)
        {
            if(d[i][k] < total)
                total = d[i][k];
        }

        if(total < 1000000000)
            printf("%d\n", total);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
