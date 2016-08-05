#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

struct data
{
    double x, y;
} arr[110];

vector <int> edge[110];

int match[110];
bool visit[110];

bool bpm(int s)
{
    int i, x = edge[s].size(), y;

    for(i = 0; i < x; ++i)
    {
        y = edge[s][i];

        if(!visit[y])
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
    int n, m, s, v, i, j, bad;
    double dist, a, b;

    while(scanf("%d %d %d %d", &n, &m, &s, &v) == 4)
    {
        for(i = 0; i < n; ++i)
            scanf("%lf %lf", &arr[i].x, &arr[i].y);

        for(i = 0; i < m; ++i)
        {
            scanf("%lf %lf", &a, &b);
            for(j = 0; j < n; ++j)
            {
                dist = sqrt((arr[j].x - a) * (arr[j].x - a) + (arr[j].y - b) * (arr[j].y - b));
                if(dist <= (double)(s * v))
                    edge[j].push_back(i);
            }
        }

        memset(match, -1, sizeof(match));
        bad = 0;
        for(i = 0; i < n; ++i)
        {
            memset(visit, 0, sizeof(visit));
            if(bpm(i))
                ++bad;
        }

        printf("%d\n", n - bad);
        for(i = 0; i < n; ++i)
            edge[i].clear();
    }
    return 0;
}
