#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int t, cnt, i, j, k, a, b, x, r, c, n, m;
    char arr[12][12], letter[12], temp;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%s", arr[i]);

        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%s", letter);
            if(strcmp(letter, "row") == 0)
            {
                scanf("%d %d", &a, &b);
                --a;
                --b;
//                printf("%d %d _______ \n", a, b);
                for(j = 0; j < n; ++j)
                {
                    temp = arr[a][j];
                    arr[a][j] = arr[b][j];
                    arr[b][j] = temp;
                }
            }

            else if(strcmp(letter, "col") == 0)
            {
                scanf("%d %d", &a, &b);
                --a;
                --b;
                for(j = 0; j < n; ++j)
                {
                    temp = arr[j][a];
                    arr[j][a] = arr[j][b];
                    arr[j][b] = temp;
                }
            }

            else if(strcmp(letter, "inc") == 0)
            {
                for(j = 0; j < n; ++j)
                    for(k = 0; k < n; ++k)
                    {
                        x = arr[j][k] + 1;
                        if(x == 58)
                            x = 48;
                        arr[j][k] = x;
                    }
            }

            else if(strcmp(letter, "dec") == 0)
            {
                for(j = 0; j < n; ++j)
                    for(k = 0; k < n; ++k)
                    {
                        x = arr[j][k] - 1;
                        if(x == 47)
                            x = 57;
                        arr[j][k] = x;
                    }
            }

            else
            {
                a = b = r = c = 0;
                while(r != n)
                {
                    if(a == n)
                    {
                        r = c = b = a = r + 1;
                        if(r == n)
                            break;
                    }
                    temp = arr[a][c];
                    arr[a][c] = arr[r][b];
                    arr[r][b] = temp;
                    ++a;
                    ++b;
                }
            }
        }

        printf("Case #%d\n", cnt);
        for(i = 0; i < n; ++i)
            printf("%s\n", arr[i]);
        printf("\n");
    }
    return 0;
}
/*
4
4
1234
5678
1234
5678
1
transpose
3
000
111
000
2
row 1 2
inc
2
90
89
1
inc
2
90
89
1
dec
*/
