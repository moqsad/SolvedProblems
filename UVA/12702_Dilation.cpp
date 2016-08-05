#include <cstdio>

char arr[110][210], letter[15][25];

int main()
{
    int t, cnt, n, m, i, j, k, l, p, q, r, c, x, y, row, column;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d\n", &n, &m);
        for(i = 1; i <= n; ++i)
            gets(arr[i]);
        m = m * 2 - 1;
        for(i = 1; i <= n; ++i)
            for(j = 0; j < m; ++j)
                if(arr[i][j] == '1')
                    arr[i][j] = '*';
        scanf("%d %d\n", &r, &c);
        for(i = 1; i <= r; ++i)
            gets(letter[i]);
        row = r / 2;
        column = (c / 2) * 2;
        c = c * 2 - 1;
        for(i = 1; i <= n; ++i)
            for(j = 0; j < m; j += 2)
            {
                if(arr[i][j] == '*')
                {
                    arr[i][j] = '1';
                    x = i - row + r;
                    y = j - column + c;
                    p = 1;
                    for(k = i - row; k < x; ++k)
                    {
                        q = 0;
                        for(l = j - column; l < y; l += 2)
                        {
                            if(k > 0 && k <= n && l >= 0 && l < m)
                            {
                                if(letter[p][q] == '1' && arr[k][l] != '*')
                                    arr[k][l] = '1';
                            }
                            q += 2;
                        }
                        ++p;
                    }
                }
            }
        printf("Case %d:\n", cnt);
        for(i = 1; i <= n; ++i)
            printf("%s\n", arr[i]);
    }
    return 0;
}
