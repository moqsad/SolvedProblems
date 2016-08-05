#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

double pro[102], calcu[102][10002], p;
int money[102];

int main()
{
    int t, cnt, n, i, j, k, ans;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %d", &p, &n);

        k = 0;

        for(i = 1; i <= n; ++i)
        {
            scanf("%d %lf", &money[i], &pro[i]);
            k += money[i];
        }

        for(i = 1; i <= k; ++i)
            calcu[0][i] = 2.0;

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= k; ++j)
            {
                if(j - money[i] < 0)
                    calcu[i][j] = calcu[i - 1][j];
                else if((calcu[i - 1][j - money[i]]) > 1.5)
                    calcu[i][j] = calcu[i - 1][j];
                else if((calcu[i - 1][j - money[i]]) < 1.5)
                    calcu[i][j] = min(calcu[i - 1][j], calcu[i - 1][j - money[i]] + (1.0 - (calcu[i - 1][j - money[i]])) * pro[i]);

//                printf("%lf   ", calcu[i][j]);
            }
//            printf("\n");
        }

        for(j = k; j > 0; --j)
            if(calcu[n][j] < p)
                break;

        printf("Case %d: %d\n", cnt, j);
    }
    return 0;
}
