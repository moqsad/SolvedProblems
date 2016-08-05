#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

struct matrix
{
    long long arr[2][2];
} identity, mat, ans;

long long mod;

matrix multiply(matrix a, matrix b)
{
    matrix ret;
    long long i, j, k;

    for(i = 0; i < 2; ++i)
    {
        for(j = 0; j < 2; ++j)
        {
            ret.arr[i][j] = 0;
            for(k = 0; k < 2; ++k)
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
    long long n, m, i, j, k;

    for(i = 0; i < 2; ++i)
        for(j = 0; j < 2; ++j)
            mat.arr[i][j] = 1;
    mat.arr[1][1] = 0;
    identity.arr[0][0] = identity.arr[1][1] = 1;

    while(scanf("%lld %lld", &n, &m) == 2)
    {
        if(n == 0 || n == 1)
            printf("%lld\n", n);

        else
        {
            mod = 1 << m;
//            printf("%lld__________________\n", mod);
            ans = func(n - 1);
            printf("%lld\n", ans.arr[0][0]);
        }
    }
    return 0;
}
