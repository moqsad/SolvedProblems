#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

#define mod 1000000007

int c[1010], w[1010];

int main()
{
    int t, cnt, n, i, j;
    long long ans;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 0; i < n; ++i)
            scanf("%d", &w[i]);

        for(i = 0; i < n; ++i)
            scanf("%d", &c[i]);

        sort(w, w + n);
        sort(c, c + n);

        ans = 1;
        i = 0;

        for(j = 0; j < n; ++j)
        {
            while(c[j] >= w[i] && i < n)
                ++i;

            ans = (ans * (i - j)) % mod;
        }

        printf("Case %d: %d\n", cnt, ans);
    }

    return 0;
}


