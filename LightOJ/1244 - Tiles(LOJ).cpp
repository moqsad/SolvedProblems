#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define mod 10007

struct matrix
{
    int arr[4][4];
};

matrix mat, identity, ans;

matrix multiply(matrix a, matrix b)
{
    int i, j, k;

    matrix ret;

    for(i = 0; i < 4; ++i)
        for(j = 0; j < 4; ++j)
        {
            ret.arr[i][j] = 0;

            for(k = 0; k < 4; ++k)
                ret.arr[i][j] = ret.arr[i][j] + a.arr[i][k] * b.arr[k][j];

            ret.arr[i][j] %= mod;
        }
    return ret;
}

matrix func(int power)
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
    int t, cnt, n, i, j;

    identity.arr[0][0] = identity.arr[1][1] = identity.arr[2][2] = identity.arr[3][3] = 1;
    mat.arr[0][0] = mat.arr[0][1] = mat.arr[0][2] = mat.arr[1][1] = mat.arr[2][0] = mat.arr[3][1] = 1;
    mat.arr[1][2] = 2;

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        if(n > 1)
        {
            ans = func(n - 2);

            printf("Case %d: %d\n", cnt, (ans.arr[0][0] * 2 + ans.arr[0][1] * 2 + ans.arr[0][2]) % mod);
        }
        else
            printf("Case %d: 1\n", cnt);
    }
    return 0;
}
