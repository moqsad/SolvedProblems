#include <stdio.h>
int main()
{
    int m, n, count, i, j, p, q, k = 0;
    char arr[100][101], string[] = "012345678";
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0)
            break;
        ++k;
        for(i = 0; i < m; ++i)
            scanf("%s", &arr[i]);
        if(k > 1)
            printf("\n");
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                if(arr[i][j] == '.')
                {
                    count = 0;
                    for(p = i - 1; p <= i + 1; ++p)
                        for(q = j - 1; q <= j + 1; ++q)
                            if(((p >= 0 && p < m) && (q >= 0 && q < n))
                                    && (arr[p][q] == '*'))
                                ++count;
                    arr[i][j] = string[count];
                }
        printf("Field #%d:\n", k);
        for(i = 0; i < m; ++i)
            printf("%s\n", arr[i]);
    }
    return 0;
}
