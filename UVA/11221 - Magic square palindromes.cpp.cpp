#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[10000], two[105][105];

int main()
{
    int t, cnt, x, i, j, k, p;
    scanf("%d", &t);
    getchar();
    for(cnt = 1; cnt <= t; ++cnt)
    {
        p = 1;
        gets(arr);
        printf("Case #%d:\n", cnt);
        j = 0;
        x = strlen(arr);
        for(i = 0; i < x; ++i)
            if(arr[i] >= 'a' && arr[i] <= 'z')
                arr[j++] = arr[i];

        x = sqrt(j);

//        printf("%d__________%d\n", j, x);

        if(x * x == j)
        {
            j = 0;
            for(i = 0; i < x; ++i)
                for(k = 0; k < x; ++k)
                    two[i][k] = arr[j++];

            j = 0;
            for(i = 0; i < x; ++i)
            {
                for(k = 0; k < x; ++k)
                    if(two[k][i] != arr[j++])
                    {
                        p = 0;
                        break;
                    }

                if(p == 0)
                    break;
            }

            if(p == 1)
            {
                j = 0;
                for(i = x - 1; i >= 0; --i)
                {
                    for(k = x - 1; k >= 0; --k)
                        if(two[k][i] != arr[j++])
                        {
                            p = 0;
                            break;
                        }

                    if(p == 0)
                        break;
                }
            }

            if(p == 1)
            {
                j = 0;
                for(i = x - 1; i >= 0; --i)
                {
                    for(k = x - 1; k >= 0; --k)
                        if(two[i][k] != arr[j++])
                        {
                            p = 0;
                            break;
                        }

                    if(p == 0)
                        break;
                }
            }
        }

        else
            p = 0;

        if(p == 1)
            printf("%d\n", x);
        else
            printf("No magic :(\n");
    }
    return 0;
}
