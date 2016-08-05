#include <stdio.h>
int main()
{
    long long arr[40], cnt, i, a, ans;
    while(1)
    {
        scanf("%lld", &a);
        if(a == 0)
            break;
        cnt = 0;
        while(a != 0)
        {
            arr[cnt] = a % 2;
            a = a / 2;
            ++cnt;
        }
        ans = 0;
        printf("The parity of ");
        for(i = cnt - 1; i >= 0; --i)
        {
            printf("%lld", arr[i]);
            if(arr[i] % 2 == 1)
                ++ans;
        }
        printf(" is %lld (mod 2).\n", ans);
    }
    return 0;
}
