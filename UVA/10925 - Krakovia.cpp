#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[1005], arr2[1005], ans[1005];

int main()
{
    int n, f, i, x, y, index, hate, temp, cnt = 0;
    while(scanf("%d %d", &n, &f) == 2)
    {
        if(n == 0 && f == 0)
            break;
        scanf("%s", arr);
        x = strlen(arr) - 1;
        for(i = 1; i < n; ++i)
        {
            scanf("%s", arr2);
            y = strlen(arr2) - 1;

            index = hate = 0;

            while(x >= 0 && y >= 0)
            {
                temp = hate + arr[x--] +  arr2[y--] - 96;
                ans[index++] = temp % 10 + 48;
                hate = temp / 10;
            }

            while(y >= 0)
            {
                temp = hate + arr2[y--] - 48;
                ans[index++] = temp % 10 + 48;
                hate = temp / 10;
            }


            while(x >= 0)
            {
                temp = hate + arr[x--] - 48;
                ans[index++] = temp % 10 + 48;
                hate = temp / 10;
            }

            if(hate > 0)
                ans[index++] = hate + 48;

            x = -1;
            while(index > 0)
                arr[++x] = ans[--index];
        }
//        for(i = 0; i <= x; ++i)
//            printf("%c", arr[i]);
        arr[x + 1] = '\0';

        index = 0;
        y = arr[0] - 48;
        while(index <= x && y < f)
            y = y * 10 + arr[++index] - 48;

        i = 0;
        while(index <= x)
        {
            ans[i++] = y / f + 48;
            y = (y % f) * 10 + arr[++index] - 48;
//            printf("__________%c\n", ans[i - 1]);
        }

        if(i > 0)
        {
            ans[i] = '\0';
            printf("Bill #%d costs %s: each friend should pay %s\n\n", ++cnt, arr, ans);
        }
        else
            printf("Bill #%d costs %s: each friend should pay 0\n\n", ++cnt, arr);
    }

        return 0;
}
/*
2 2
24323223
99909111
-24232334
*/
