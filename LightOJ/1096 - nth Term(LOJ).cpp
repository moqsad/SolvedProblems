#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define mod 10007

struct matrix
{
    int arr[4][4];
};

matrix multiply(matrix a, matrix b)
{
    matrix ret;
    int i, j, k;
    for(i = 0; i < 4; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            ret.arr[i][j] = 0;
            for(k = 0; k < 4; ++k)
                ret.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            ret.arr[i][j] = ret.arr[i][j] % mod;
        }
    }
    return ret;
}

matrix mat, identity, ans;


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
    int t, cnt, i, j, n, a, b, c;

    for(i = 0; i < 4; ++i)
        identity.arr[i][i] = 1;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &n, &a, &b, &c);

        if(n > 2)
        {
            for(i = 0; i <  4; ++i)
                for(j = 0; j < 4; ++j)
                    mat.arr[i][j] = 0;

            mat.arr[0][0] = a;
            mat.arr[0][2] = b;
            mat.arr[0][3] = mat.arr[1][0] = mat.arr[2][1] = mat.arr[3][3] = 1;

            ans = func(n - 2);

            printf("Case %d: %d\n", cnt, (ans.arr[0][3] * c) % mod);
        }

        else
            printf("Case %d: %d\n", cnt, 0);
    }
    return 0;
}
