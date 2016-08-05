#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

char first[300], second[300], p[300], q[300], ans[600];

int main()
{
    int i, j, k, l, m, n, cnt, x, y, z, a, b, c;
    while(scanf("%s %s", first, second) == 2)
    {
        if(first[0] == '0' || second[0] == '0')
            printf("0\n");
        else
        {
            memset(p, 0, sizeof(p));
            memset(q, 0, sizeof(q));
            a = strlen(first) - 1;
            b = strlen(second) - 1;
            l = 1;
            m = 0;
            for(i = a; i >= 0; --i)
            {
                k = 0;
                z = 0;
                x = first[i] - 48;
                for(j = b; j >= 0; --j)
                {
                    y = second[j] - 48;
                    z = x * y + z;
                    p[k++] = z % 10;
                    //printf("%d****", p[k - 1]);
                    z /= 10;
                }
                if(z > 0)
                {
                    p[k++] = z;
                    //printf("%d****", p[k - 1]);
                }
                //printf("\n");
                c = p[0] + q[0];
                ans[m++] = c % 10;
                //printf("%d////////////////////////\n", ans[m - 1]);
                c /= 10;
                n = l;
                l = 0;
                if(k == n)
                {
                    for(j = 1; j < k; ++j)
                    {
                        q[l++] = (q[j] + p[j] + c) % 10;
                        c = (q[j] + p[j] + c) / 10;
                        //printf("%d____", q[l - 1]);
                    }
                    if(c > 0)
                    {
                        q[l++] = c;
                        //printf("%d____", q[l - 1]);
                    }
                }

                else if(k > n)
                {
                    for(j = 1; j < n; ++j)
                    {
                        q[l++] = (q[j] + p[j] + c) % 10;
                        c = (q[j] + p[j] + c) / 10;
                        //printf("%d____", q[l - 1]);
                    }
                    for(j = n; j < k; ++j)
                    {
                        q[l++] = (p[j] + c) % 10;
                        c = (p[j] + c) / 10;
                        //printf("%d____", q[l - 1]);
                    }
                    if(c > 0)
                    {
                        q[l++] = c;
                        //printf("%d____", q[l - 1]);
                    }
                }
                else
                {
                    for(j = 1; j < k; ++j)
                    {
                        q[l++] = (q[j] + p[j] + c) % 10;
                        c = (q[j] + p[j] + c) / 10;
                        //printf("%d____", q[l - 1]);
                    }
                    for(j = k; j < n; ++j)
                    {
                        q[l++] = (q[j] + c) % 10;
                        c = (q[j] + c) / 10;
                        //printf("%d____", q[l - 1]);
                    }
                    if(c > 0)
                    {
                        q[l++] = c;
                        //printf("%d____", q[l - 1]);
                    }
                }

                //printf("\n\n");
            }
            --l;
            while(l >= 0)
            {
                printf("%d", q[l]);
                --l;
            }
            --m;
            while(m >= 0)
            {
                printf("%d", ans[m]);
                --m;
            }
            printf("\n");
        }
    }
    return 0;
}
/*
52343723267
2342332
*/
