#include <cstdio>
#include <cstring>
using namespace std;

struct matrix
{
    long long arr[6][6];
};

matrix mat, identity, ans;

long long mod;

matrix multiply(matrix a, matrix b)
{
    matrix ret;

    long long i, j, k;

    for(i = 0; i < 6; ++i)
        for(j = 0; j < 6; ++j)
        {
            ret.arr[i][j] = 0;
            for(k = 0; k < 6; ++k)
                ret.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            ret.arr[i][j] = ret.arr[i][j] % mod;
        }
    return ret;
}

matrix func(long long power)
{
    if(power == 0)
        return identity;

    matrix ret = func(power / 2);

    ret = multiply(ret, ret);

    if(power % 2 == 1)
        ret = multiply(ret, mat);

    return ret;
}

int main()
{
    long long t, cnt, i, j, k, f[3], g[3], x, y, a1, b1, c1, a2, b2, c2, q, n;

    for(i = 0; i < 6; ++i)
        identity.arr[i][i] = 1;

    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld %lld %lld %lld", &a1, &b1, &c1, &a2, &b2, &c2);
        scanf("%lld %lld %lld %lld %lld %lld", &f[0], &f[1], &f[2], &g[0], &g[1], &g[2]);

        scanf("%lld", &mod);

        scanf("%lld", &q);

        for(i = 0; i < 6; ++i)
            for(j = 0; j < 6; ++j)
                mat.arr[i][j] = 0;

        mat.arr[0][0] = a1;
        mat.arr[0][1] = b1;
        mat.arr[0][5] = c1;
        mat.arr[3][2] = c2;
        mat.arr[3][3] = a2;
        mat.arr[3][4] = b2;
        mat.arr[1][0] = mat.arr[2][1] = mat.arr[4][3] = mat.arr[5][4] = 1;

//        for(i = 0; i < 6; ++i)
//        {
//            for(j = 0; j < 6; ++j)
//            {
//                printf("%lld___", mat.arr[i][j]);
//            }
//            printf("\n");
//        }

        printf("Case %lld:\n", cnt);
        for(k = 0; k < q; ++k)
        {
            scanf("%lld", &n);
            if(n > 2)
            {
                ans = func(n - 2);

//                for(i = 0; i < 6; ++i)
//                {
//                    for(j = 0; j < 6; ++j)
//                    {
//                        printf("%lld++++", ans.arr[i][j]);
//                    }
//                    printf("\n");
//                }

                x = (ans.arr[0][0] * f[2] + ans.arr[0][1] * f[1] + ans.arr[0][2] * f[0] + ans.arr[0][3] * g[2] + ans.arr[0][4] * g[1] + ans.arr[0][5] * g[0]) % mod;
                y = (ans.arr[3][0] * f[2] + ans.arr[3][1] * f[1] + ans.arr[3][2] * f[0] + ans.arr[3][3] * g[2] + ans.arr[3][4] * g[1] + ans.arr[3][5] * g[0]) % mod;
                printf("%lld %lld\n", x, y);
            }
            else
                printf("%lld %lld\n", f[n] % mod, g[n] % mod);
        }
    }
    return 0;
}
