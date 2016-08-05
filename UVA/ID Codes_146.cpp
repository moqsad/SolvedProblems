#include "bits/stdc++.h"
using namespace std;

int main()
{
    int i, j, k, x;
    char stock[100], arr[100], ch, temp;
    while(scanf("%s", arr) == 1)
    {
        if(arr[0] == '#')
            break;
        j = 0;
        x = strlen(arr) - 1;
        for(i = x; i > 0; --i)
        {
            if(arr[i] <= arr[i - 1])
            {
                stock[j++] = arr[i];
            }
            else
                break;
        }
        if(i == 0)
            printf("No Successor\n");
        else
        {
            stock[j] = arr[i];
            ch = arr[--i];
            for(k = 0; k <= j; ++k)
            {
                if(stock[k] > ch)
                {
                    temp = arr[i];
                    arr[i] = stock[k];
                    stock[k] = temp;
                    arr[++i] = '\0';
                    stock[++j] = '\0';
                    printf("%s%s\n", arr, stock);
                    break;
                }
            }
        }
    }
    return 0;
}
