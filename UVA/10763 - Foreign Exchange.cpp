#include <cstdio>
#include <iostream>
#include <map>
#include <set>
using namespace std;

map <long long, long long> mm;
map <long long, long long> nn;
//set <long long> myset;
//set <long long> :: iterator it;

long long arr[500100];

int main()
{
    long long n, i, j, a, b, p, x;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;
        j = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%lld %lld", &a, &b);
            x = a * 1000000000 + b;

            if(nn.find(x) == nn.end())
            {
                mm[x] = 1;
                nn[x] = b * 1000000000 + a;
                arr[j++] = x;
            }
            else
            {
                mm[x] = mm[x] + 1;
            }
        }

        p = 1;

        for(i = 0; i < j; ++i)
        {
            if(mm[arr[i]] != mm[nn[arr[i]]])
            {
                p = 0;
                break;
            }
        }

        if(p == 1)
            printf("YES\n");
        else
            printf("NO\n");

        mm.clear();
        nn.clear();
    }
    return 0;
}
