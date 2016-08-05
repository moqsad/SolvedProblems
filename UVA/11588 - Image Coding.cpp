#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

map <char, int> mm;

int num[500];

int main()
{
    int t, cnt, r, c, m, n, i, j, k, total, sum;
    char arr[25][25];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        mm.clear();
        memset(num, 0, sizeof(num));
        scanf("%d %d %d %d", &r, &c, &m, &n);
        for(i = 0; i < r; ++i)
            scanf("%s", arr[i]);
        k = 0;
        for(i = 0; i < r; ++i)
            for(j = 0; j < c; ++j)
            {
                if(mm.find(arr[i][j]) == mm.end())
                    mm[arr[i][j]] = ++k;
                ++num[mm[arr[i][j]]];
            }
        total = 0;
        for(i = 1; i <= k; ++i)
        {
            if(num[i] > total)
                total = num[i];
        }
        sum = 0;
        for(i = 1; i <= k; ++i)
        {
            if(num[i] < total)
                sum += num[i] * n;
            else
                sum += num[i] * m;
        }
        printf("Case %d: %d\n", cnt, sum);
    }
    return 0;
}
