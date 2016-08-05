#include "bits/stdc++.h"
using namespace std;

int lcs(void);

int value[110][110], depend, arr[110][110], arr1[110], arr2[110], m, n;

int main()
{
    int ans, cnt, p = 0;
    arr[0][0] = '0';
    while(scanf("%d %d", &m, &n) == 2)
    {
        if(m == 0 && n == 0)
            break;
        for(cnt = 1; cnt <= m; ++cnt)
            scanf("%d", &arr1[cnt]);
        for(cnt = 1; cnt <= n; ++cnt)
            scanf("%d", &arr2[cnt]);
        ans = lcs();
        printf("Twin Towers #%d\n", ++p);
        printf("Number of Tiles : %d\n\n", ans);
    }

    return 0;
}

int lcs(void)
{
    int a, b, cnt, i, j, x, y, z, maximum;

    memset(value, 0, sizeof(value));

    for(cnt = 1; cnt <= m; ++cnt)
    {
        arr[0][cnt] = arr1[cnt];
    }

    for(cnt = 1; cnt <= n; ++cnt)
    {
        arr[cnt][0] = arr2[cnt];
    }
    maximum = 0;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
        {
            x = value[i - 1][j];
            y = value[i][j - 1];

            if(arr[0][j] == arr[i][0])
                depend = 1;
            else
                depend = 0;

            z = value[i - 1][j - 1] + depend;

            maximum = x > y ? x : y;
            maximum = maximum > z ? maximum : z;

            value[i][j] = maximum;
        }

    return maximum;
}
