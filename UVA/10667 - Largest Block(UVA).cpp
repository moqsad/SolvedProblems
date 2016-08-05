#include <bits/stdc++.h>
using namespace std;

int sum[105][105], arr[105][105];

int main()
{
    int n, m, i, j, k, l, x, y, z, max_, p, r1, r2, c1, c2;
    scanf("%d", &p);
    while(p--)
    {
        scanf("%d %d", &n, &m);

        memset(arr, 0, sizeof(arr));

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            for(k = r1 - 1; k <= r2 - 1; ++k)
                for(l = c1 - 1; l <= c2 - 1; ++l)
                    arr[k][l] = 1;
        }

        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                x = y = z = 0;

                if(i - 1 >= 0)
                    x = sum[i - 1][j];
                if(j - 1 >= 0)
                    y = sum[i][j - 1];
                if(i - 1 >= 0 && j - 1 >= 0)
                    z = sum[i - 1][j - 1];

                sum[i][j] = x + y - z + arr[i][j];
            }
        }

        max_ = 0;

        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
            {
                for(k = i; k < n; ++k)
                    for(l = j; l < n; ++l)
                    {
                        x = y = z = 0;

                        if(i - 1 >= 0)
                            x = sum[i - 1][l];
                        if(j - 1 >= 0)
                            y = sum[k][j - 1];
                        if(i - 1 >= 0 && j - 1 >= 0)
                            z = sum[i - 1][j - 1];

                        if(sum[k][l] - (x + y - z) == 0)
                            max_ = max(max_, (k - i + 1) * (l - j + 1));
                    }
            }

        printf("%d\n", max_);
    }
    return 0;
}

