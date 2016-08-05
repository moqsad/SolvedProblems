#include "bits/stdc++.h"
using namespace std;

map <int, int> mm;

int main()
{
    int a, b, c, d, cnt, i = 0;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4)
    {
        mm.clear();
        if(a == 0 && b == 0 && c == 0 && d == 0)
            break;
        cnt = 0;
        d = (d * a + b) % c;
        while(mm.find(d) == mm.end())
        {
            ++cnt;
            mm[d] = 1;
            d = (d * a + b) % c;
        }
        printf("Case %d: %d\n", ++i, cnt);
    }
    return 0;
}
