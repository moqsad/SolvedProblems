#include <cstdio>
#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;

int arr[150];

char s[1000000];

int main()
{
    long long j = 0, i, sum, x;
    for(i = '0'; i <= '9'; ++i)
        arr[i] = j++;

    for(i = 'A'; i <= 'Z'; ++i)
        arr[i] = j++;

    for(i = 'a'; i <= 'z'; ++i)
        arr[i] = j++;

//    printf("%d %d\n", arr['-'], ']');
    while(gets(s))
    {
        x = strlen(s);
        sum = 0;
        j = 0;
        for(i = 0; i < x; ++i)
        {
            sum += arr[s[i]];
            if(arr[s[i]] > j)
                j = arr[s[i]];
        }

        if(sum == 0)
            printf("2\n");
        else
        {
            for(i = j + 1; i <= 62; ++i)
            {
                if(sum % (i - 1) == 0)
                    break;
            }

            if(i <= 62)
                printf("%lld\n", i);
            else
                printf("such number is impossible!\n");
        }
    }
    return 0;
}
