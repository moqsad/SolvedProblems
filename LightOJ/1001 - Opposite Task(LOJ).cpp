#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, n, x;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        x = n / 2;
        printf("%d %d\n", x, n - x);
    }
    return 0;
}
