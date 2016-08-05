#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

int main()
{
    int t, cnt, a, b, i, j, n, w, ans, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &w);
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d", &a, &b);
            v.push_back(b);
        }
        sort(v.begin(), v.end());

        i = ans = 0;
        while(i < n)
        {
            ++ans;
            x = w + v[i++];
            while(v[i] <= x)
            {
                ++i;
                if(i == n)
                    break;
            }
        }
        printf("Case %d: %d\n", cnt, ans);
        v.clear();
    }
    return 0;
}
