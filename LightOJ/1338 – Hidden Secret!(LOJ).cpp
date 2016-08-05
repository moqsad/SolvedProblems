#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

char arr[300], ch;
int num1[100], num2[100];

int main()
{
    int t, cnt, p, i, j, x, y, n;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        gets(arr);
        x = strlen(arr);
        for(i = 0; i < x; ++i)
            if(arr[i] != ' ')
                ++num1[toupper(arr[i])];

        gets(arr);
        x = strlen(arr);
        for(i = 0; i < x; ++i)
            if(arr[i] != ' ')
                ++num2[toupper(arr[i])];

        p = 1;
        for(i = 65; i <= 90; ++i)
        {
            if(num1[i] != num2[i])
            {
                p = 0;
                break;
            }
        }

        if(p == 0)
            printf("Case %d: No\n", cnt);
        else
            printf("Case %d: Yes\n", cnt);
    }
    return 0;
}
