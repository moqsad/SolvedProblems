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

int main()
{
    int t, cnt;
    unsigned long long n;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%llu", &n);

        n = n * 10;

        if(n % 9 == 0)
            printf("Case %d: %llu %llu\n", cnt, n / 9 - 1, n / 9);
        else
            printf("Case %d: %llu\n", cnt, n / 9);
    }

    return 0;
}
