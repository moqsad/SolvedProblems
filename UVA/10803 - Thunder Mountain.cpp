#include <cstdio>
#include <cmath>

double dist[110][110], a[110], b[110];

double small(double a, double b)
{
    return (a < b) ? a : b;
}

void floyd(int n)
{
    int i, j, k;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            for(k = 1; k <= n; ++k)
                dist[j][k] = small(dist[j][k], dist[j][i] + dist[i][k]);
}

int main()
{
    int t, i, j, cnt, n, p;
    double x, y, z, total;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
            scanf("%lf %lf", &a[i], &b[i]);

        for(i = 1; i <= n;  ++i)
            for(j = 1; j <= n; ++j)
                dist[i][j] = 9999999999.0;

        for(i = 1; i <= n; ++i)
        {
            for(j = i + 1; j <= n; ++j)
            {
                x = a[i] - a[j];
                y = b[i] - b[j];
                z = sqrt(x * x + y * y);
                if(z <= 10)
                {
                    dist[i][j] = z;
                    dist[j][i] = z;
                }
            }
        }

        floyd(n);

        total = 0;
        p = 1;
        for(i = 1; i <= n; ++i)
        {
            for(j = i + 1; j <= n; ++j)
            {
                z = dist[i][j];
                if(z == 9999999999.0)
                {
                    p = 0;
                    break;
                }
                if(z > total)
                    total = z;
            }
            if(p == 0)
                break;
        }

        printf("Case #%d:\n", cnt);
        if(p == 1)
            printf("%.4lf\n\n", total);
        else
            printf("Send Kurdy\n\n");
    }
    return 0;
}

/*
2
5
0 0
10 0
10 10
13 10
13 14
2
0 0
10 1
fabs(total*1e4 - floor(total*1e4) - 0.5) > 1e-2 is a useless line............
*/
