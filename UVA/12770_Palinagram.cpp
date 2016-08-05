#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int num[30], i, j, x;
    char arr[510];
    while(scanf("%s", arr) == 1)
    {
        if(arr[0] == '#')
            break;
        memset(num, 0, sizeof(num));
        x = strlen(arr);
        for(i = 0; i < x; ++i)
            ++num[arr[i] - 'a'];

        for(i = 25; i >= 0; --i)
        {
            if(num[i] % 2 == 1)
                break;
        }

        for(j = 0; j < i; ++j)
        {
            if(num[j] % 2 == 1)
                printf("%c", j + 'a');
        }
        printf("\n");
    }
    return 0;
}
