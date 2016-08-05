#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long int t, n, cnt, i, j, arr[110][110], p, x, y;
    char ch;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf(" %c = %lld", &ch, &n);
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
            {
                scanf("%lld", &arr[i][j]);
            }
        p = 1;
        y = n / 2 + 1;
        x = n - 1;
        for(i = 0; i < y; ++i)
        {
            for(j = 0; j < n; ++j)
                if(arr[i][j] == arr[x - i][x - j] && arr[i][j] > -1);
                else
                {
                    p = 0;
                    break;
                }
                if(p == 0)
                    break;
        }
        if(p == 1)
            printf("Test #%lld: Symmetric.\n", cnt);
        else
            printf("Test #%lld: Non-symmetric.\n", cnt);
    }
    return 0;
}
