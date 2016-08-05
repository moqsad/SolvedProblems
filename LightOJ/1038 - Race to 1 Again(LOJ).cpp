#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

double ans[100005];

int divisor[100005];

int main()
{
    int t, cnt, i, j, k, x, y, n;

    double sum, divide;

    ans[1] = 0.0, ans[2] = 2.0, ans[3] = 2.0, ans[4] = 2.5, ans[5] = 2.0;

    for(i = 6; i <= 100000; ++i)
    {
        x = sqrt(i);
        k = 0;
        for(j = 2; j < x; ++j)
        {
            if(i % j == 0)
            {
                divisor[k++] = j;
                divisor[k++] = i / j;
            }
        }

        if(i % x == 0)
        {
            if(i / x == x)
                divisor[k++] = x;
            else
            {
                divisor[k++] = x;
                divisor[k++] = i / x;
            }
        }

        divide = k + 2;

        sum = 2.0 / divide;

        for(j = 0; j < k; ++j)
        {
            sum += (ans[divisor[j]] + 1.0) / divide;
        }

        ans[i] = sum / (1 - 1.0 / divide);
    }

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        printf("Case %d: %.7lf\n", cnt, ans[n]);
    }
    return 0;
}
