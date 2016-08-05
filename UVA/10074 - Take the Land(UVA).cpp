#include <bits/stdc++.h>
using namespace std;

int sum[105][105], arr[105][105], ans[105][105];

int main()
{
    int n, m, i, j, k, l, x, y, z, max_;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break ;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
                scanf("%d", &arr[i][j]);

        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                x = y = z = 0;

                if(i - 1 >= 0)
                    x = sum[i - 1][j];
                if(j - 1 >= 0)
                    y = sum[i][j - 1];
                if(i - 1 >= 0 && j - 1 >= 0)
                    z = sum[i - 1][j - 1];

                sum[i][j] = x + y - z + arr[i][j];
//                printf("%d ", sum[i][j]);
            }
//            printf("\n");
        }

        max_ = 0;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                for(k = i; k < n; ++k)
                    for(l = j; l < m; ++l)
                    {
                        x = y = z = 0;

                        if(i - 1 >= 0)
                            x = sum[i - 1][l];
                        if(j - 1 >= 0)
                            y = sum[k][j - 1];
                        if(i - 1 >= 0 && j - 1 >= 0)
                            z = sum[i - 1][j - 1];

//                            printf("%d %d %d %d__ %d\n", sum[k][l], x, y, z,  sum[k][l] - (x + y - z));
//
                        if(sum[k][l] - (x + y - z) == 0)
                            max_ = max(max_, (k - i + 1) * (l - j + 1));
                    }
            }

        printf("%d\n", max_);
    }
    return 0;
}
