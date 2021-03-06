#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

struct matrix
{
    unsigned long long arr[2][2];
};

matrix mat, identity, ans;

matrix multiply(matrix a, matrix b)
{
    matrix ret;

    unsigned long long i, j, k;

    for(i = 0; i < 2; ++i)
        for(j = 0; j < 2; ++j)
        {
            ret.arr[i][j] = 0;
            for(k = 0; k < 2; ++k)
                ret.arr[i][j] += a.arr[i][k] * b.arr[k][j];
        }
    return ret;
}

matrix func(unsigned long long power)
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
    unsigned long long t, cnt, p, q, n, total, i, j, k;

    identity.arr[0][0] = identity.arr[1][1] = 1;
    mat.arr[1][0] = 1, mat.arr[1][1] = 0;

    scanf("%llu", &t);

    for(cnt  = 1; cnt <= t; ++cnt)
    {
        scanf("%llu %llu %llu", &p, &q, &n);

        if(n == 0)
            printf("Case %llu: %llu\n", cnt, 2);

        else if(n == 1)
            printf("Case %llu: %llu\n", cnt, p);

        else
        {
            mat.arr[0][0] = p, mat.arr[0][1] = - q;

//            for(i = 0; i < 2; ++i)
//                for(j = 0; j < 2; ++j)
//                printf("%llu____\n", mat.arr[i][j]);

            ans = func(n - 1);

            total = 0;

//            for(i = 0; i < 2; ++i)
//                for(j = 0; j < 2; ++j)
//                printf("%llu____\n", ans.arr[i][j]);

            total += ans.arr[0][0] * p;
            total += ans.arr[0][1] * 2;

            printf("Case %llu: %llu\n", cnt, total);
        }
    }
    return 0;
}
