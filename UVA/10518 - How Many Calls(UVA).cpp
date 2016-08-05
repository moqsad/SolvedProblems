#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

struct matrix
{
    long long arr[3][3];
} identity, mat, ans;

long long mod;

matrix multiply(matrix a, matrix b)
{
    matrix ret;
    long long i, j, k;

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            ret.arr[i][j] = 0;
            for(k = 0; k < 3; ++k)
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
    long long n, cnt = 0;

    mat.arr[0][0] = mat.arr[0][1] = mat.arr[0][2] = mat.arr[1][0] = mat.arr[2][2] = 1;
    identity.arr[0][0] = identity.arr[1][1] = identity.arr[2][2] = 1;

    while(scanf("%lld %lld", &n, &mod) == 2)
    {
        if(n == 0 && mod == 0)
            break;

        if(n == 0 || n == 1)
            printf("Case %lld: %lld %lld %lld\n", ++cnt, n, mod, 1 % mod);

        else
        {
            ans = func(n - 1);
            printf("Case %lld: %lld %lld %lld\n", ++cnt, n,  mod, (ans.arr[0][0] + ans.arr[0][1] + ans.arr[0][2]) % mod);
        }
    }
    return 0;
}

