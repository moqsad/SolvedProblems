#include <bits/stdc++.h>
using namespace std;

int p[] = {-1, 0, 1, -1, 1, -1, 0, 1}, q[] = {1, 1, 1, 0, 0, -1, -1, -1};
char arr[55][55], s[55];

int main()
{
    int m, n, t, i, j, cnt, k, l, x, o, y, r, c;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; ++i)
            scanf("%s", arr[i]);

        scanf("%d", &k);
        for(l = 0; l < k; ++l)
        {
            scanf("%s", s);
            x = strlen(s);
            for(i = 0; i < m; ++i)
            {
                for(j = 0; j < n; ++j)
                {
                    for(o = 0; o < 8; ++o)
                    {
                        y = 0;
                        r = i;
                        c = j;
                        while(y < x)
                        {
                            if(r >= 0 && r < m && c >= 0 && c < n && tolower(arr[r][c]) == tolower(s[y]))
                                r += p[o], c += q[o], ++y;
                            else
                                break ;
//                                printf("%d %d____________%d %d\n", i, j, r, c);
                        }
                        if(y == x)
                            break;
                    }
                    if(o < 8)
                        break;
                }
                if(j < n)
                    break;
            }
            printf("%d %d\n", i + 1, j + 1);
        }

        if(cnt < t)
            printf("\n");
    }

    return 0;
}

