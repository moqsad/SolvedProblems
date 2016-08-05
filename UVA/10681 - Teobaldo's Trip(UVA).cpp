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
    int arr[105][105];
};

matrix identity, mat, info;
int c;

matrix multiply(matrix p, matrix q)
{
    matrix ret;

    int i, j, k;

    for(i = 1; i <= c; ++i)
    {
        for(j = 1; j <= c; ++j)
        {
            ret.arr[i][j] = 0;

            for(k = 1; k <= c; ++k)
                ret.arr[i][j] += p.arr[i][k] * q.arr[k][j];

            if(ret.arr[i][j] > 0)
                ret.arr[i][j] = 1;
        }
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
    int l, s, e, d, i, j, a, b;

    for(i = 1; i < 105; ++i)
        identity.arr[i][i] = 1;

    while(scanf("%d %d", &c, &l) == 2)
    {
        if(c == 0 && l == 0)
            break;

        for(i = 1; i <= c; ++i)
            for(j = 1; j <= c; ++j)
                mat.arr[i][j] = 0;

        for(i = 0; i < l; ++i)
        {
            scanf("%d %d", &a, &b);
            mat.arr[a][b] = 1;
            mat.arr[b][a] = 1;
        }

        scanf("%d %d %d", &s, &e, &d);

        info = func(d);

        if(info.arr[s][e] == 1)
            printf("Yes, Teobaldo can travel.\n");
        else
            printf("No, Teobaldo can not travel.\n");
    }

    return 0;
}

/*
3 0
1 1 5
*/
