#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

struct data
{
    int x, y;
} point[1005], arr[1000010];

bool comp(data p, data q)
{
    if(p.x != q.x)
        return p.x < q.x;
    return p.y < q.y;
}

int main()
{
    int t, cnt, n, i, j, k, ans, x, y, pre;
    data info;
    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 0; i < n; ++i)
            scanf("%d %d", &point[i].x, &point[i].y);

        k = 0;
        for(i = 0; i < n; ++i)
            for(j = i + 1; j < n; ++j)
            {
                x = point[i].x + point[j].x;
                y = point[i].y + point[j].y;

                info.x = x;
                info.y = y;

                arr[k++] = info;
            }

        sort(arr, arr + k, comp);

        ans = 0;
        info = arr[0];
        pre = 0;
        for(i = 1; i < k; ++i)
        {
            if(arr[i].x != info.x || arr[i].y != info.y)
            {
                ans += ((i - pre) * ((i - pre) - 1)) / 2;
                info = arr[i];
                pre = i;
            }
        }
        ans += ((i - pre) * ((i - pre) - 1)) / 2;

        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}

/*
10
6
0 0
0 1
1 0
1 1
2 0
2 1
*/
