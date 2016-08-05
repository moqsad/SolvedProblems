#include "bits/stdc++.h"
using namespace std;

int cmpfunc (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}
map <int, int> mm;

int main()
{
    int cnt, n, q, i = 0, b;
    while(scanf("%d %d", &n, &q) == 2)
    {
        if(n == 0 && q == 0)
            break;
        mm.clear();
        int a[n];
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%d", &a[cnt]);
        }
        qsort(a, n, sizeof(int), cmpfunc);
        for(cnt = 0; cnt < n; ++cnt)
        {
            if(mm.find(a[cnt]) == mm.end())
                mm[a[cnt]] = cnt;
        }
        ++i;
        printf("CASE# %d:\n", i);
        for(cnt = 0; cnt < q; ++cnt)
        {
            scanf("%d", &b);
            if(mm.find(b) != mm.end())
                printf("%d found at %d\n", b, mm[b] + 1);
            else
                printf("%d not found\n", b);
        }
    }
    return 0;
}
