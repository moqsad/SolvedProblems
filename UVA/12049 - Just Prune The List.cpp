#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

map <long long, long long> mm, nn;

long long arr1[5050], arr2[5050];

int main()
{
    long long cnt, t, i, j, k , m, n, ans, a;
    scanf("%lld", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lld %lld", &n, &m);
        ans = j = k = 0;

        for(i = 0; i < n; ++i)
        {
            scanf("%lld", &a);
            if(mm.find(a) == mm.end())
            {
                mm[a] = 1;
                arr1[j++] = a;
            }
            else
                mm[a] = mm[a] + 1;
//            printf("%lld------\n", mm[a]);
        }

        for(i = 0; i < m; ++i)
        {
            scanf("%lld", &a);
            if(nn.find(a) == nn.end())
            {
                nn[a] = 1;
                arr2[k++] = a;
            }
            else
                nn[a] = nn[a] + 1;
//            printf("%lld++++++\n", nn[a]);
        }

        for(i = 0; i < j; ++i)
        {
            if(nn.find(arr1[i]) == nn.end())
                ans += mm[arr1[i]];
            else
            {
                if(mm[arr1[i]] > nn[arr1[i]])
                    ans += mm[arr1[i]] - nn[arr1[i]];
                else
                    ans += nn[arr1[i]] - mm[arr1[i]];
                nn[arr1[i]] = 0;
            }
//            printf("%lld ___ %lld____\n", arr1[i], ans);
        }

        for(i = 0; i < k; ++i)
        {
            ans += nn[arr2[i]];
        }

        printf("%lld\n", ans);

        mm.clear();
        nn.clear();
    }
    return 0;
}
