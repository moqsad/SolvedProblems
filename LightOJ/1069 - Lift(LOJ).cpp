#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, sum, a, b;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &a, &b);
        sum = abs(b - a);
        sum = sum * 4 + 3 + 3 + 5 + a * 4 + 3 + 5;
        printf("Case %d: %d\n", cnt, sum);
    }
    return 0;
}


