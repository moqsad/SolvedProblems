#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    int t, cnt, x, k, y, z;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &x, &k);
        z = x % k;
        printf("%d %d\n", k - z, z);
    }
    return 0;
}
