#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int count, ans, x, y, q;
    char arr[1000];
    double m;
    while(1)
    {
        scanf("%s", arr);
        if(arr[0] == '0')
            break;
        ans = 0;
        if(strlen(arr) >= 4)
        {
            ans = (arr[0] - 48) * 1000 + (arr[1] - 48) * 100 + (arr[2] - 48) * 10 + (arr[3] - 48);
            ans = ans % 17;
        }
        for(count = 1; count < strlen(arr) / 4; ++count)
        {
            ans *= 10000;
            ans += (arr[4 * count + 0] - 48) * 1000 + (arr[4 * count + 1] - 48) * 100
                   + (arr[4 * count + 2] - 48) * 10 + (arr[4 * count + 3] - 48);
            ans = ans % 17;
        }
        x = strlen(arr) % 4;
        y = 1;
        q = strlen(arr) - x;
        m = x;
        ans *= pow(10, m);
        for(count = strlen(arr) - 1; count >= q; --count)
        {
            ans += (arr[count] - 48) * y;
            y *= 10;
        }
        if(ans % 17 == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
