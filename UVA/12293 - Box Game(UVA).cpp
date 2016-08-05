#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, pre;
    while(scanf("%lld", &n) && n)
    {
        pre = 3;

        while(pre + pre + 1 <= n)
            pre += pre + 1;

        if(pre == n && n >= 3)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}
