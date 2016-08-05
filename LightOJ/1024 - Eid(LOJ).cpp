#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

int prime[35], arr[120], visit[10010], end_;

map <int, int> mm;

vector <int> extra;

char ans[70010];

void sieve(void)
{
    int cnt  = 0, i, j, k;
    prime[cnt++] = 2;
    for(i = 3; i < 110; i += 2)
    {
        if(!arr[i])
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 110; j += k)
                arr[j] = 1;
        }
    }
//    printf("%d\n", cnt);
}

void Eid(int multi)
{
    int k, x = 0;
    for(k = 0; k < end_; ++k)
    {
        x += (ans[k] - 48) * multi;
        ans[k] = x % 10 + 48;
        x = x / 10;
    }
    while(x > 0)
    {
        ans[k++] = x % 10 + 48;
        x /= 10;
    }
    end_ = k;
}

int main()
{
    sieve();

    int x, z, cnt, t, n, i, j, b, a;

    scanf("%d", &t);
    for(cnt = 1;  cnt <= t; ++cnt)
    {
        scanf("%d",&n);
        memset(visit, 0, sizeof(visit));
        for(j = 0; j < n; ++j)
        {
            scanf("%d", &a);
            x = sqrt(a) + 2;
            i = 0;

            while(prime[i] < x)
            {
                if(a % prime[i] == 0)
                {
                    b = 1;
                    while(a % prime[i] == 0)
                    {
                        a /= prime[i];
                        b *= prime[i];
                    }

                    visit[prime[i]] = max(b, visit[prime[i]]);
                }
                ++i;
            }

            if(a > 1)
                visit[a] = max(visit[a], a);
        }

        ans[0] = '1';
        end_ = 1;

        for(i = 2; i < 10001; ++i)
        {
            if(visit[i] > 0)
                Eid(visit[i]);
        }

        printf("Case %d: ", cnt);

        for(i = end_ - 1; i >= 0; --i)
            printf("%c", ans[i]);

        printf("\n");
    }
    return 0;
}
