#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int p[2][6];

int fact(int a, int i)
{
    while(a % 2 == 0)
    {
        a /= 2;
        ++p[i][2];
    }
    while(a % 3 == 0)
    {
        a /= 3;
        ++p[i][3];
    }
    while(a % 5 == 0)
    {
        a /= 5;
        ++p[i][5];
    }
    return a;
}

int main()
{
    int a, b, x, y, ans;
    while(scanf("%d %d", &a, &b) == 2)
    {
        memset(p, 0, sizeof(p));
        x = fact(a, 0);
        y = fact(b, 1);
        if(x == y)
        {
            ans = 0;
            if(p[0][2] > p[1][2])
                ans += p[0][2] - p[1][2];
            else
                ans += p[1][2] - p[0][2];
            if(p[0][3] > p[1][3])
                ans += p[0][3] - p[1][3];
            else
                ans += p[1][3] - p[0][3];
            if(p[0][5] > p[1][5])
                ans += p[0][5] - p[1][5];
            else
                ans += p[1][5] - p[0][5];
            printf("%d\n", ans);
        }
        else
            printf("-1\n");
    }
    return 0;
}
