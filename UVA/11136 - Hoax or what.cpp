//#include <cstdio>
//#include <set>
//#include <cstring>
//#include <iostream>
//using namespace std;

#include <bits/stdc++.h>
using namespace std;

multiset <long long> myset;
multiset <long long> :: iterator it;

int main()
{
    long long n, i, j, total, a, k;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;
        total = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%lld", &k);
            for(j = 0; j < k; ++j)
            {
                scanf("%lld", &a);
                myset.insert(a);
            }

            it = myset.end();
            --it;
            total += *it;
            myset.erase(it);
            it = myset.begin();
            total -= *it;
            myset.erase(it);

        }
        printf("%lld\n", total);
        myset.clear();
    }
    return 0;
}
