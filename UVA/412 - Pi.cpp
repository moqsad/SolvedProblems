#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int arr[60];

int gcd(int a, int b)
{
    int r;
    while(b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, x, y, i, j, k, cnt;
    double ans, p, q;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        cnt = 0;
        k = 0;
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        x = n - 1;
        for(i = 0; i < x; ++i)
        {
            for(j = i + 1; j < n; ++j)
            {
                y = gcd(arr[i], arr[j]);
                if(y == 1)
                    ++k;
                ++cnt;
            }
        }
        if(k > 0)
        {
            p = cnt;
            q = k;
            ans = 6 * p / q;
            printf("%.6lf\n", sqrt(ans));
        }
        else
            printf("No estimate for this data set.\n");
    }
    return 0;
}
