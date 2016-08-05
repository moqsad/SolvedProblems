#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct matrix
{
    int arr[75][75];
};

matrix identity, mat, ac;

int x;

matrix multiply(matrix a, matrix b)
{
    int i, j, k;
    matrix ret;
    for(i = 0; i < x; ++i)
        for(j = 0; j < x; ++j)
        {
            ret.arr[i][j] = 0;

            for(k = 0; k < x; ++k)
                ret.arr[i][j] = (ret.arr[i][j] + a.arr[i][k] * b.arr[k][j]) % 10;
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
    int t, cnt, i, j, k, n, power, ans;

    for(i = 0; i < 65; ++i)
        identity.arr[i][i] = 1;

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &power);

        x = n + n;

        for(i = 0; i < x; ++i)
            for(j = 0; j < x; ++j)
                mat.arr[i][j] = 0;

        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                scanf("%d", &mat.arr[i][j]);

        j = 0;
        for(; i < x; ++i)
            mat.arr[i][j++] = 1;

        for(i = n; i < x; ++i)
            mat.arr[i][j++] = 1;

//        for(i = 0; i < x; ++i)
//        {
//            for(j = 0; j < x; ++j)
//                printf("%d__",mat.arr[i][j]);
//            printf("\n");
//        }

        ac = func(power);

//        for(i = 0; i < x; ++i)
//        {
//            for(j = 0; j < x; ++j)
//                printf("%d ",ac.arr[i][j]);
//            printf("\n");
//        }

        printf("Case %d:\n", cnt);

        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                ans = 0;
                for(k = 0; k < n; ++k)
                    ans = (ans + ac.arr[i+n][k] * mat.arr[k][j]) % 10;
                printf("%d", ans);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
2
3 45645546
1 4 6
6 5 2
1 2 3
*/
