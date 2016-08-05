#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector <long long> v;

int main()
{
    long long t, cnt, a, i, ans, x, y, j;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        while(scanf("%lld", &a) == 1)
        {
            if(a == 0)
                break;
            v.push_back(-a);
        }
        sort(v.begin(), v.end());
        a = v.size();
        ans = 0;
        for(i = 0; i <  a; ++i)
        {
            y = x = - v[i];
            for(j = 0; j < i; ++j)
            {
                x = x * y;
                if(x > 5000000)
                    break;
            }
            ans += x;
            if(ans > 5000000)
                break;
        }

        ans *= 2;

        if(ans  <= 5000000)
            printf("%lld\n", ans);
        else
            printf("Too expensive\n");

            v.clear();
    }
    return 0;
}
