#include <stdio.h>
int main()
{
    int k, number[130], i, j, x, temp, cnt, m = 0;
    char arr[1050];
    while(gets(arr))
    {
        ++m;
        if(m > 1)
            printf("\n");
        for(k = 0; k < 130; ++k)
        {
            number[k] = 0;
        }
        k = 0;
        while(arr[k] != '\0')
        {
            x = arr[k];
            ++number[x];
            ++k;
        }
        for(i = 129; i >= 32; --i)
        {
            temp = number[i];
            x = i;
            for(j = 129; j >= 32; --j)
            {
                if((number[j] < temp && number[j] > 0) || (number[j] == temp && j > x))
                {
                    temp = number[j];
                    x = j;
                }
            }
            if(temp != 0)
            {
                printf("%d %d\n", x, temp);
                number[x] = 0;
            }
        }
    }
    return 0;
}
