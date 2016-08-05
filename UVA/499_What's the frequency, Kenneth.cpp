#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[150000];
int num[150];

int main()
{
    int total, i, x;
    while(gets(arr))
    {
        total = 0;
        x = strlen(arr);
        memset(num, 0, sizeof(num));

        for(i = 0; i < x; ++i)
        {
            if(isalpha(arr[i]))
            {
                ++num[arr[i]];
                if(num[arr[i]] > total)
                    total = num[arr[i]];
            }
        }

        for(i = 65; i <= 90; ++i)
        {
            if(num[i] == total)
                printf("%c", i);
        }

        for(i = 97; i <= 122; ++i)
        {
            if(num[i] == total)
                printf("%c", i);
        }

        printf(" %d\n", total);
    }
    return 0;
}
