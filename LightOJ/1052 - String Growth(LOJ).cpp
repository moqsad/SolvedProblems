#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct matrix
{
    long long arr[2][2];
};

#define mod 1000000007
#define max_ 1000000000

matrix identity, mat, ans, ans2;

long long p, pre;

matrix multiply(matrix a, matrix b)
{
    long long i, j, k;

    matrix ret;

    for(i = 0; i < 2; ++i)
        for(j = 0; j < 2; ++j)
        {
            ret.arr[i][j] = 0;
            for(k = 0; k < 2; ++k)
            {
                ret.arr[i][j] = ret.arr[i][j] + a.arr[i][k] * b.arr[k][j];

                if(pre == 0)
                    ret.arr[i][j] %= mod;

                else
                {
                    if(i != 0 || j != 0)
                    {
                        if(ret.arr[i][j] > max_)
                        {
                            p = 0;
                            return ret;
                        }
                    }
                }
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
    if(p == 0)
        return ret;

    if(power % 2 == 1)
    {
        ret = multiply(ret, mat);
        if(p == 0)
            return ret;
    }

    return ret;
}

int main()
{
    long long t, cnt, b, a, b1, a1, b2, a2, temp, N, X, M, Y, K, i, j;

    identity.arr[0][0] = identity.arr[1][1] = 1;

    mat.arr[0][0] = mat.arr[0][1] = mat.arr[1][0] = 1;

    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld %lld %lld", &N, &X, &M, &Y, &K);

        pre = p = 1;

        ans = func(N - 1);

        ans2 = func(M - 1);

//        printf("\n");
//        for(i = 0; i < 2; ++i)
//        {
//            for(j = 0; j < 2; ++j)
//            {
//                printf("%lld ", ans.arr[i][j]);
//            }
//            printf("\n");
//        }

//        printf("\n");
//        for(i = 0; i < 2; ++i)
//        {
//            for(j = 0; j < 2; ++j)
//            {
//                printf("%lld ", ans2.arr[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");

        if(p == 0)
            printf("Case %lld: Impossible\n", cnt);

        else
        {
            b1 = ans.arr[0][0] + ans.arr[1][0];
            a1 = ans.arr[0][1] + ans.arr[1][1];

            b2 = ans2.arr[0][0] + ans2.arr[1][0];
            a2 = ans2.arr[0][1] + ans2.arr[1][1];

            temp = b1 * a2 - b2 * a1;
            b = a2 * X - a1 * Y;
            a = b1 * Y - b2 * X;

//            printf("---->%lld %lld\n---->%lld %lld\n---- %lld %lld %lld____\n\n", b1, a1, b2, a2, temp, a, b);

            if((temp != 0) && (b % temp == 0) && (a % temp == 0) && (b / temp >= 0) && (a / temp >= 0))
            {
                b /= temp;
                a /= temp;

                pre = 0;
                p = 1;

                ans = func(K - 1);

//                for(i = 0; i < 2; ++i)
//                {
//                    for(j = 0; j < 2; ++j)
//                    {
//                        printf("%lld__ ", ans.arr[i][j]);
//                    }
//                    printf("\n");
//                }

                temp = (ans.arr[0][0] * b) % mod + (ans.arr[0][1] * a) % mod;
                temp += (ans.arr[1][0] * b) % mod + (ans.arr[1][1] * a) % mod;

                printf("Case %lld: %lld\n", cnt, temp % mod);
            }
            else
                printf("Case %lld: Impossible\n", cnt);
        }
    }
    return 0;
}
