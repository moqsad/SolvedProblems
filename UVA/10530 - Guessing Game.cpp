#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, i = 0, j, num[150];
    char arr[15], letter[150];
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        getchar();
        gets(arr);
        if(strcmp(arr, "too high") == 0)
        {
            letter[i] = '>';
        }
        else if(strcmp(arr, "too low") == 0)
        {
            letter[i] = '<';
        }
        else
        {
            for(j = 0; j < i; ++j)
            {
                if(letter[j] == '>')
                {
                    if(!(num[j] > n))
                        break;
                }

                else
                {
                    if(!(num[j] < n))
                        break;
                }
            }
            if(j == i)
                printf("Stan may be honest\n");
            else
                printf("Stan is dishonest\n");
            i = -1;
        }
        num[i] = n;
        ++i;
    }
    return 0;
}
