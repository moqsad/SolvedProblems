#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

long long a[20], f[20], n, mod, d;

struct matrix
{
    long long arr[20][20];
} identity, mat, ans;

matrix multiply(matrix a, matrix b)
{
    matrix ret;
    long long i, j, k;

    for(i = 1; i <= d; ++i)
    {
        for(j = 1; j <= d; ++j)
        {
            ret.arr[i][j] = 0;
            for(k = 1; k <= d; ++k)
                ret.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            ret.arr[i][j] %= mod;
        }
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
    long long i, j, sum;

    for(i = 1; i <= 15; ++i)
    {
        identity.arr[i][i] = 1;
        mat.arr[i][i - 1] = 1;
    }

    while(scanf("%lld %lld %lld", &d, &n, &mod) == 3)
    {
        if(d == 0 && n == 0 && mod == 0)
            break ;

        j = d;
        for(i = 1; i <= d; ++i)
            scanf("%lld", &mat.arr[1][i]);

//        for(i = 1; i <= d; ++i)
//        {
//            for(j = 1; j <= d; ++j)
//            printf("%lld ", mat.arr[i][j]);
//            printf("hehe..........\n");
//        }

        for(i = 1; i <= d; ++i)
            scanf("%lld", &f[i]);

        if(n <= d)
            printf("%lld\n", f[n]);
        else
        {
            ans = func(n - d);
            sum = 0;
            j = d;
            for(i = 1; i <= d; ++i)
                sum += ans.arr[1][i] * f[j--];
            printf("%lld\n", sum % mod);
        }
    }
    return 0;
}
