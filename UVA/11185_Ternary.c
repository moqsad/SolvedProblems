#include <stdio.h>
int main()
{
    long long int arr[20], a, count, i;
    while(1)
    {
        scanf("%lld", &a);
        if(a < 0)
            break;
        if(a == 0)
            printf("0\n");
        else
        {
            count = 0;
            while(a != 0)
            {
                arr[count] = a % 3;
                a /= 3;
                ++count;
            }
            i = count - 1;
            for(count = i; count >= 0; --count)
                printf("%lld", arr[count]);
            printf("\n");
        }
    }
    return 0;
}
