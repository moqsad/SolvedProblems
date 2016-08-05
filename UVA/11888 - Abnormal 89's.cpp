#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char arr[200010];

int main()
{
    int i, k, j, x, y, cnt, t, p;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%s", arr);
        x = strlen(arr);
        p = 0;
        for(i = 1; i < x; ++i)
        {
            y = i / 2;
            k = i;
            p = 1;
            for(j = 0; j < y; ++j)
            {
                if(arr[j] != arr[--k])
                {
                    p = 0;
                    break;
                }
            }

            if(p == 1)
            {
                k = x;
                y = i + (x - i) / 2;
                for(j = i; j < y; ++j)
                {
                    if(arr[j] != arr[--k])//====
                    {
                        p = 0;
                        break;
                    }
                }

                if(p == 1)
                {
                    printf("alindrome\n");
                    break;
                }
            }
        }

        if(p == 0)
        {
            p = 1;
            y = x / 2;
            k = x;
            for(j = 0; j < y; ++j)
            {
                if(arr[j] != arr[--k])
                {
                    p = 0;
                    break;
                }
            }


            if(p == 1)
                printf("palindrome\n");
            else
                printf("simple\n");
        }
    }
    return 0;
}
