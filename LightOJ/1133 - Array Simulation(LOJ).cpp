#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long arr[110], apato[110];

int main()
{
    long long t, cnt, n, m, i, j, k, a, b, temp;
    char ch;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &m);
        for(i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);

        for(i = 0; i < m; ++i)
        {
            scanf(" %c", &ch);
            if(ch == 'S')
            {
                scanf("%lld", &a);
                for(j = 0; j < n; ++j)
                    arr[j] += a;
            }
            else if(ch == 'M')
            {
                scanf("%lld", &a);
                for(j = 0; j < n; ++j)
                    arr[j] *= a;
            }
            else if(ch == 'D')
            {
                scanf("%lld", &a);
                for(j = 0; j < n; ++j)
                    arr[j] /= a;
            }
            else if(ch == 'R')
            {
                k = n;
                for(j = 0; j < n; ++j)
                    apato[j] = arr[--k];
                for(j = 0; j < n; ++j)
                    arr[j] = apato[j];
            }
            else
            {
                scanf("%lld %lld", &a, &b);
                temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
            }
        }
        printf("Case %lld:\n", cnt);
        printf("%lld", arr[0]);
        for(i = 1; i < n; ++i)
            printf(" %lld", arr[i]);
        printf("\n");
    }
    return 0;
}
