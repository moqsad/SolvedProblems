#include <stdio.h>
int main()
{
    int a, b, c, d, e, x, y, z, cnt, arr[40000], i = 0, n, num[5], value[5], j, p, det = 0, k, l, q;
    for(a = 0; a < 10; ++a)
    {
        for(b = 0; b < 10; ++b)
        {
            if(b != a)
                for(c = 0; c < 10; ++c)
                {
                    if(c != a && c != b)
                        for(d = 0; d < 10; ++d)
                        {
                            if(d != a && d != b && d != c)
                            {
                                for(e = 0; e < 10; ++e)
                                {
                                    if(e != a && e != b && e != c && e != d)
                                        arr[i++] = a * 10000 + b * 1000 + c * 100 + d * 10 + e;
                                }
                            }
                        }
                }
        }
    }
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        if(det > 0)
            printf("\n");
        ++det;
        p = 0;
        for(cnt = 0; cnt < i; ++cnt)
        {
            y = arr[cnt];
            x = arr[cnt] * n;
            if(x < 100000)
            {
                if(x > 10000)
                {
                    j = 0;
                    while(x > 0)
                    {
                        num[j++] = x % 10;
                        x = x / 10;
                    }
                    q = 0;
                    while(y != 0)
                    {
                        z = y % 10;
                        y /= 10;
                        for(k = 0; k < j; ++k)
                        {
                            if(z == num[k])
                            {
                                q = 1;
                                break;
                            }
                        }
                        if(q == 1)
                            break;
                    }
                    if(arr[cnt] < 10000)
                        if(0 == num[0] || 0 == num[1] || 0 == num[2] || 0 == num[3])
                            q = 1;
                    if(q == 0 && num[0] != num[1] && num[0] != num[2] && num[0] != num[3] && num[0] != num[4] && num[1] != num[2] &&
                            num[1] != num[3] && num[1] != num[4] && num[2] != num[3] && num[2] != num[4] && num[3] != num[4])
                    {
                        p = 1;
                        for(j = 4; j >=  0; --j)
                            printf("%d", num[j]);
                        if(arr[cnt] < 10000)
                            printf(" / 0%d = %d", arr[cnt], n);
                        else
                            printf(" / %d = %d", arr[cnt], n);
                        printf("\n");
                    }
                }
            }
            else
            {
                if(p == 0)
                    printf("There are no solutions for %d.\n", n);
                break;
            }
        }
    }
    return 0;
}
