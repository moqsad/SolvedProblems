#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long ans[100100], temp[100100], a[110];
int main()
{
    long long t, cnt, n, k, i, j, l, m, x, y, z, total;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &k);
        for(i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        memset(ans, 0, sizeof(ans));
        memset(temp, 0, sizeof(temp));
        ans[0] = 1;
        temp[0] = 1;

        for(i = 1; i <= n; ++i)
        {
            scanf("%lld", &x);
            y = a[i];
            for(j = 0; j < y; ++j)
            {
                total = 0;
                l = z = j + y;
                m = 1;
                while(z <= k)
                {
                    if(m <= x)
                    {
                        if(ans[z - y] == 1)
                            ans[z] = 1;
                        total = total + temp[z];
                        ++m;
                    }

                    else
                    {
                        if(total > 0)
                            ans[z] = 1;
                        total = total + temp[z] - temp[l];
                        l += y;
                    }
                    z += y;
                }
            }

            for(j = 1; j <= k; ++j)
            {
                temp[j] = ans[j];
//                printf("i = %lld, j = %lld, ans = %lld\n", i, j, ans[j]);
            }
        }

        total = 0;
        for(i = 1; i <= k; ++i)
            if(ans[i] == 1)
                ++total;
        printf("Case %lld: %lld\n", cnt, total);
    }
    return 0;
}

/*
1
50 800
1 6 8 13 15 17 18 20 21 23 24 27 30 31 32
33 34 35 39 40 43 44 46 48 52 53 54 55 57
60 61 64 65 67 68 70 71 72 76 77 80 84 87
88 89 90 92 93 94 99
4 18 10 2 6 13 15 5 2 4 5 7 9 9 18 11 4 5
15 7 18 2 19 12 13 12 13 4 2 12 2 11 19 10
12 1 20 18 18 15 16 2 17 8 9 14 10 14 2 4
*/

