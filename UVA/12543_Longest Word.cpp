#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

char arr[1000], temp[1000], mid[1000];

int main()
{
    int total = 0, i, j, x;
    while(scanf("%s", arr) == 1)
    {
        i = 0;
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
            j = 0;
            while((tolower(arr[i]) >= 97 && tolower(arr[i]) <= 122) || arr[i] == '-')
            {
                mid[j++] = arr[i];
                ++i;
            }
            mid[j] = '\0';
            if(j > total)
            {
                total = j;
                strcpy(temp, mid);
            }
        }
        if(strcmp(arr, "E-N-D") == 0)
        {
            for(i = 0; i < total; ++i)
                printf("%c", tolower(temp[i]));
            printf("\n");
            total = 0;
        }
    }
    return 0;
}
// || (arr[i] >= 65 && arr[i] <= 90)
