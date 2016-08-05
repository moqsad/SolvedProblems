#include <cstdio>
using namespace std;

int main()
{
    long long int p, q, x, y, u, v, z, i, j, k, ans;
    while(scanf("%lld %lld", &p, &q) == 2)
    {
        if(p < 0 && q < 0)
            break;
        ans = 0;
        i = 1;
        j = 0;
        k = 0;
        while(q / i > 0)
        {
            x = p / 10 / i;
            y = q / 10 / i;
            z = y - x - 1;
            z *= 45;
//            printf("%d++++++\n", z);
            u = (p / i) % 10;
            if(u > 0)
            {
                j = 1;
                ++k;
            }
            z = z + 45 - u * (u - 1) / 2;
//            printf("%d_______\n", z);
            v = (q / i) % 10;
            z = z + v * (v + 1) / 2;
//            printf("%d||||||||\n", z);
            if(j == 1 && k > 1)
                z -= u;
//            printf("%d#########\n", z);
            ans += z;
            i *= 10;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
