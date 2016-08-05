#include "bits/stdc++.h"
using namespace std;

int visit[1050], i;
double dist[1050], num[1050][1050];
int bfs(int x, int y);
queue <int> Q;

int main()
{
    int j;
    double f[1050], g[1050], a, b, x, y;
    char arr[50], in[25], out[25];
    while(scanf("%lf %lf", &a, &b) == 2)
    {
        if(a == 0 && b == 0)
            break;
        memset(num, 0, sizeof(num));
        i = 0;
        x = a * b * 60;
        getchar();
        while(gets(arr))
        {
            if(arr[0] == '\0')
                break;
            sscanf(arr, "%s %s", in, out);
            f[i] = atof(in);
            g[i] = atof(out);
            for(j = 0; j < i; ++j)
            {
                a = f[i] - f[j];
                b = g[i] - g[j];
                y = sqrt(a * a + b * b);
                if(x >= y)
                {
                    num[i][j] = 1;
                    num[j][i] = 1;
                }
            }
            ++i;
        }
        j = bfs(0, 1);
        if(j > 0)
            printf("Yes, visiting %d other holes.\n", j - 1);
        else
            printf("No.\n");
    }
    return 0;
}

int bfs(int x, int y)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    while(!Q.empty())
        Q.pop();

    visit[x] = 1;
    dist[x] = 0;
    Q.push(x);

    int u, j;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();

        for(j = 0; j < i; j++)
        {
            if(num[u][j] == 1 && visit[j] == 0)
            {
                dist[j] = dist[u] + 1;
                if(j == y)
                {
                    return dist[j];
                }
                visit[j] = 1;
                Q.push(j);
            }
        }
    }
    return 0;
}
