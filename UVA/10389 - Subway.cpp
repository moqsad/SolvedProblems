#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

double cost[210][210], d[210];
long long int k, finish;
char arr[60000], letter[210];

struct data
{
    long long int city;
    double dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void dijkstra(void)
{
    long long int i, x, y;
    data u, v;
    priority_queue <data> Q;
    for(i = 0; i < k; ++i)
        d[i] = 21474836450000000.0;

    u.city = 0;
    u.dist = 0.0;
    Q.push(u);
    d[0] = 0.0;

    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();
        for(i = 0; i < k; ++i)
        {
            v.city = i;
            v.dist = d[u.city] + cost[u.city][i];
            if(v.dist < d[v.city])
            {
                d[v.city] = v.dist;
                Q.push(v);
            }
        }
    }
}

int main()
{
    long long int cnt, i, j, x, n, m, t, a[210], b[210];
    double y, z, p;
    scanf("%lld\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
//        for(i = 0; i < 210; ++i)
//            for(j = 0; j < 210; ++j)
//                cost[i][j] = -5.0;
        memset(cost, 0.0, sizeof(cost));

        scanf("%lld %lld %lld %lld", &a[0], &b[0], &a[1], &b[1]);
        getchar();

        k = 2;

        while(gets(arr))
        {
            if(arr[0] == '\0')
                break;
            i = 0;
            x = strlen(arr);

            j = 0;
            while(isdigit(arr[i]))
            {
                letter[j++] = arr[i];
                ++i;
            }
            letter[j] = '\0';
            a[k] = atol(letter);
            while(arr[i] == ' ')
                ++i;

            j = 0;
            while(isdigit(arr[i]))
            {
                letter[j++] = arr[i];
                ++i;
            }
            letter[j] = '\0';
            b[k] = atol(letter);
            while(arr[i] == ' ')
                ++i;
            ++k;

            while(i < x)
            {
                j = 0;
                while(isdigit(arr[i]) || arr[i] == '-')
                {
                    letter[j++] = arr[i];
                    ++i;
                }
                letter[j] = '\0';
                a[k] = atol(letter);
                while(arr[i] == ' ')
                    ++i;

                j = 0;
                while(isdigit(arr[i]) || arr[i] == '-')
                {
                    letter[j++] = arr[i];
                    ++i;
                }
                letter[j] = '\0';
                b[k] = atol(letter);
                if(a[k] == -1 && b[k] == -1)
                    break;
                y = a[k] - a[k-1];
                z = b[k] - b[k-1];
                p = sqrt(y * y + z * z) * .0015;
                cost[k][k-1] = p;
                cost[k-1][k] = p;

                while(arr[i] == ' ')
                    ++i;
                ++k;
            }
        }

        for(i = 0; i < k; ++i)
            for(j = 0; j  < k; ++j)
            {
                if((long long int)cost[i][j] == 0L)
                {
                    y = a[i] - a[j];
                    z = b[i] - b[j];
                    p = sqrt(y * y  + z * z) * .006;
                    cost[i][j] = p;
                    cost[j][i] = p;
                }
            }


        dijkstra();

        printf("%.0lf\n", d[1]);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
/*
1

0 0 0 10000
0 0 0   5000 -1 -1
0 5000   0 10000 -1 -1
*/
