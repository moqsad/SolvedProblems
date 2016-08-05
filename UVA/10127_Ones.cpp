#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, cnt, x;
    while(scanf("%d", &n) == 1)
    {
        x = 1;
        cnt = 1;
        while(x % n > 0)
        {
            x %=  n;
            x = x * 10 + 1;
            ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
