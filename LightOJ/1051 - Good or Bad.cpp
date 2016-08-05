#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char arr[55];
int num[55];

/* Wrong Answer*/

int main()
{
    int n, m, i, j, p, q, r, cnt, t, x, y, a, b;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        p = 0;
        scanf("%s", arr);
        n = strlen(arr);
        for(i = 0; i < n; ++i)
        {
            if(arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
                num[i] = 0;
            else if(arr[i] == '?')
                num[i] = 1;
            else
                num[i] = 2;
        }

        m = n - 2;

        for(i = 0; i < m; ++i)
        {
            if(num[i] == 1)
            {
                if(i > 0 && num[i - 1] != 1 && num[i + 1] != 1 &&  num[i - 1] != num[i + 1])
                {
                    if(num[i - 1] == 0)
                    {
                        x = i - 2;
                        y = i + 4;
                    }

                    else
                    {
                        x = i - 4;
                        y = i + 2;
                    }


                    if(x >= 0 && y < n)
                    {
                        for(j = i - 2; j >= x; --j)
                            if(num[j] != num[i - 1])
                                break;

                        if(j < x)
                        {
                            for(j = i + 2; j <= y; ++j)
                                if(num[j] != num[i + 1])
                                    break;

                            if(j > y)
                            {
                                break;
                            }
                        }
                    }
                }
                continue;
            }

            if(num[i] == 0)
                x = i + 3;

            else
                x = i + 5;

            j = 0;
            if(x <= n)
                for(j = i + 1; j < x; ++j)
                    if(num[i] != num[j])
                        break;

            if(j == x)
            {
                break;
            }
        }

        if(i < m)
            printf("Case %d: BAD\n", cnt);

        else
        {
            for(i = 0; i < m; ++i)
            {
                if(num[i] == 1)
                {
                    q = 0;
                    j = 0;
                    x = i + 3;
                    if(x <= n)
                        for(j = i + 1; j < x; ++j)
                        {
                            if(q == 0)
                            {
                                if(num[j] != 1)
                                {
                                    r = num[j];
                                    if(r == 2)
                                    {
                                        x += 2;
                                        if(x > n)
                                            break;
                                    }
                                    q = 1;
                                }
                            }

                            else if(num[j] != r && num[j] != 1)
                            {
                                break;
                            }
                        }

                    if(j == x)
                    {
                        break;
                    }
                    continue;
                }

                if(num[i] == 0)
                    x = i + 3;

                else
                    x = i + 5;

                j = 0;
                if(x <= n)
                    for(j = i + 1; j < x; ++j)
                        if(num[i] != num[j] && num[j] != 1)
                            break;

                if(j == x)
                    break;
            }

            if(i < m)
                printf("Case %d: MIXED\n", cnt);
            else
                printf("Case %d: GOOD\n", cnt);
        }
    }
    return 0;
}
