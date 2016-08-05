#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

struct data
{
    int u;
    int v;
};

data arr[1010];
bool comp(data p, data q)
{
    if(p.v != q.v)
        return p.v < q.v;
    else
        return p.u > q.u;
}

int main()
{
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}, x, y, cnt, t, i, j, ans, a;
    arr[1].u = 1;
    arr[1].v = 1;
    arr[2].u = 2;
    arr[2].v = 2;
    arr[3].u = 3;
    arr[3].v = 2;
    arr[4].u = 4;
    arr[4].v = 3;
    for(cnt = 5; cnt <= 1000; ++cnt)
    {
        y = cnt;
        x = sqrt(cnt) + 2;
        i = 0;
        ans = 1;
        while(prime[i] < x)
        {
            if(y % prime[i] == 0)
            {
                j = 1;
                while(y % prime[i] == 0)
                {
                    y /= prime[i];
                    ++j;
                }
                ans *= j;
            }
            ++i;
        }
        if(y > 1)
            ans *= 2;
        arr[cnt].u = cnt;
        arr[cnt].v = ans;
    }
    sort(arr + 1, arr + 1001, comp);
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &a);
        printf("Case %d: %d\n", cnt, arr[a].u);
    }
    return 0;
}
