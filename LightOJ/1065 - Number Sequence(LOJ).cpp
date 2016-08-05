#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int mat[2][2], mat2[2][2];

void power(int p)
{
    if(p == 0 || p == 1)
        return ;

    power(p / 2);

    int temp[2][2];

    temp[0][0] = mat[0][0];
    temp[0][1] = mat[0][1];
    temp[1][0] = mat[1][0];
    temp[1][1] = mat[1][1];

    mat[0][0] = (temp[0][0] * temp[0][0] + temp[0][1] * temp[1][0]) % 10000;
    mat[0][1] = (temp[0][0] * temp[0][1] + temp[0][1] * temp[1][1]) % 10000;
    mat[1][0] = (temp[1][0] * temp[0][0] + temp[1][1] * temp[1][0]) % 10000;
    mat[1][1] = (temp[1][0] * temp[0][1] + temp[1][1] * temp[1][1]) % 10000;

    if(p % 2 == 1)
    {
        temp[0][0] = mat[0][0];
        temp[0][1] = mat[0][1];
        temp[1][0] = mat[1][0];
        temp[1][1] = mat[1][1];

        mat[0][0] = (temp[0][0] * mat2[0][0] + temp[0][1] * mat2[1][0]) % 10000;
        mat[0][1] = (temp[0][0] * mat2[0][1] + temp[0][1] * mat2[1][1]) % 10000;
        mat[1][0] = (temp[1][0] * mat2[0][0] + temp[1][1] * mat2[1][0]) % 10000;
        mat[1][1] = (temp[1][0] * mat2[0][1] + temp[1][1] * mat2[1][1]) % 10000;
    }
}

int main()
{
    int t, cnt, a, b, n, m, mod,i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &a, &b, &n, &m);

        mat[0][0] = mat2[0][0] = 1;
        mat[0][1] = mat2[0][1] = 1;
        mat[1][0] = mat2[1][0] = 1;
        mat[1][1] = mat2[1][1] = 0;

        mod = 1;
        for(i = 0; i < m; ++i)
            mod *= 10;

        if(n == 0)
            printf("Case %d: %d\n", cnt, a % mod);

        else if(n == 1)
            printf("Case %d: %d\n", cnt, b % mod);

        else
        {
            power(n - 1);
//            printf("%d %d\n%d %d\n", mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
            printf("Case %d: %d\n", cnt, (mat[0][0] * b + mat[0][1] * a) % mod);
        }
    }
    return 0;
}
