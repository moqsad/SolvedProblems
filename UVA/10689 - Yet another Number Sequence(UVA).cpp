#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

struct matrix
{
    int arr[2][2];
};

int mod;
matrix identity, mat, info;

matrix multiply(matrix p, matrix q)
{
    matrix ret;
    int i, j, k;

    for(i = 0; i < 2; ++i)
        for(j = 0; j < 2; ++j)
        {
            ret.arr[i][j] = 0;

            for(k = 0; k < 2; ++k)
                ret.arr[i][j] += p.arr[i][k] * q.arr[k][j];

            ret.arr[i][j] = ret.arr[i][j] % mod;
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
    int t, a, b, n, m, ans;

    identity.arr[0][0] = identity.arr[1][1] = 1;
    mat.arr[0][0] = mat.arr[0][1] = mat.arr[1][0] = 1;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d %d %d", &a, &b, &n, &m);
        mod = 1;
        ans = 0;

        while(m--)
            mod *= 10;

        if(n > 0)
        {
            info = func(n - 1);
            ans = info.arr[0][0] * b + info.arr[0][1] * a;
            printf("%d\n", ans % mod);
        }
        else
            printf("%d\n", a % mod);
    }

    return 0;
}
