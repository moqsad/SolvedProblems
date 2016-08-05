#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define mod 4294967296

struct data
{
    int u, v;
};

data pair_[40];

struct matrix
{
    unsigned long long arr[36][36];
};

matrix ans, mat, identity;

matrix multiply(matrix a, matrix b)
{
    unsigned long long i, j, k;

    matrix ret;

    for(i = 0; i < 36; ++i)
    {
        for(j = 0; j < 36; ++j)
        {
            ret.arr[i][j] = 0;

            for(k = 0; k < 36; ++k)
                ret.arr[i][j] += (a.arr[i][k] * b.arr[k][j]) % mod;

            ret.arr[i][j] %= mod;
        }
    }
    return ret;
}

matrix func(unsigned long long power)
{
    if(power == 0)
        return identity;

    matrix ret = func(power / 2);

    ret = multiply(ret , ret);

    if(power % 2 == 1)
        ret = multiply(ret, mat);

    return ret;
}

int main()
{
    int t, cnt, n, i, j, k = 0;
    unsigned long long total;

    for(i = 1; i < 9; ++i)
        for(j = i + 2; j < 11; ++j)
        {
            pair_[k].u = i;
            pair_[k].v = j;
            ++k;
        }

    for(i = 0; i < 36; ++i)
    {
        identity.arr[i][i] = 1;
        for(j = 0; j < 36; ++j)
        {
            mat.arr[i][j] = 0;
            if((abs(pair_[j].u - pair_[i].u) > 1) && (abs(pair_[j].u - pair_[i].v) > 1))
            {
                if((abs(pair_[j].v - pair_[i].u) > 1) && (abs(pair_[j].v - pair_[i].v) > 1))
                    mat.arr[i][j] = 1;
            }
        }
    }

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        if(n == 1)
            printf("Case %d: %d\n", cnt, 36);

        else
        {
            ans = func(n - 1);

            total = 0;

            for(i = 0; i < 36; ++i)
                for(j = 0; j < 36; ++j)
                    total += ans.arr[i][j];

            printf("Case %d: %llu\n", cnt, total % mod);
        }
    }
    return 0;
}
