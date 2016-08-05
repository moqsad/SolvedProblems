#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define mod 4294967296

struct matrix
{
    unsigned long long arr[55][55];
};

matrix identity, mat, ans;

unsigned long long  k;

matrix multiply(matrix a, matrix b)
{
    unsigned long long i, j, l;
    matrix ret;

    for(i = 0; i <= k; ++i)
    {
        for(j = 0; j <= k; ++j)
        {
            ret.arr[i][j] = 0;
            for(l = 0; l <= k; ++l)
                ret.arr[i][j] = (ret.arr[i][j] + (a.arr[i][l] * b.arr[l][j])) % mod;
        }
    }
    return ret;
}

matrix func(unsigned long long power)
{
    if(power == 0)
        return identity;

    matrix ret2 = func(power / 2);

    ret2 = multiply(ret2, ret2);

    if(power % 2 == 1)
        ret2 = multiply(ret2, mat);

    return ret2;
}

int main()
{
    unsigned long long t, cnt, i, j, l, m, x, n, ans2;

    for(i = 0; i < 55; ++i)
        identity.arr[i][i] = 1;


    scanf("%llu", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%llu %llu", &n, &k);

        ++k;
        for(i = 0; i <= k; ++i)
            for(j = 0; j <= k; ++j)
                mat.arr[i][j] = 0;

        for(i = 0; i < k; ++i)
        {
            l = i;
            for(j = 0; j <= i; ++j)
            {
                ans2 = 1;
                x =  (i - l) + 1;
                for(m = 1; m <= l; ++m)
                    ans2 = ((ans2 * x++) / m);
                mat.arr[i][j] = ans2 % mod;
                --l;
            }
        }

        mat.arr[k][k] = mat.arr[k][k - 1] = 1;

//        for(i = 0; i < k; ++i)
//        {
//            for(j = 0; j < k; ++j)
//                printf("%llu ", mat.arr[i][j]);
//            printf("\n");
//        }

        ans = func(n);

        ans2 = 0;
        for(i = 0; i < k; ++i)
            ans2 = (ans2 + ans.arr[k][i]);

        printf("Case %llu: %llu\n", cnt, ans2 % mod);
    }
    return 0;
}
