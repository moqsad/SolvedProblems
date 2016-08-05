#include <stdio.h>

int arr[15];

int func(int k)
{
    int x = 0, i = 0;
    while(k > 0)
    {
        arr[i++] = k % 2;
        k /= 2;
    }

    while(i--)
        x = x * 10 + arr[i];
    return x;
}

int main()
{
    int t, cnt, a, b, c, d, q, p, w, x, y, z;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        scanf("%d.%d.%d.%d", &w, &x, &y, &z);
//        printf("%d__\n", z);
        p = 1;

        q = func(a);
        if(q == w)
        {
            q = func(b);
            if(q == x)
            {
                q = func(c);
                if(q == y)
                {
                    q = func(d);
                    if(q != z)
                        p = 0;
                }
                else
                    p = 0;
            }
            else
                p = 0;
        }
        else
            p = 0;

        if(p == 1)
            printf("Case %d: Yes\n", cnt);
        else
            printf("Case %d: No\n", cnt);
    }
    return 0;
}
