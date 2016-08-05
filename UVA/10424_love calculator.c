#include <stdio.h>
#include <ctype.h>
int main()
{
    int count, x, i;
    float sum[2], p, q, ans;
    char arr[2][100];
    while(scanf(" %[^\n] %[^\n]", &arr[0], &arr[1]) == 2)
    {
        sum[0] = 0;
        sum[1] = 0;
        for(count = 0; count < 2; ++count)
        {
            i = 0;
            while(arr[count][i] != '\0')
            {
                x = tolower(arr[count][i]) - 96;
                if(x >= 1 && x <= 26)
                sum[count] += x;
                ++i;
            }
            if((int)sum[count] % 9 != 0)
            sum[count] = (int)sum[count] % 9;
            else
            sum[count] = 9;
        }
        p = (sum[0] < sum[1]) ? sum[0] : sum[1];
        q = (sum[0] > sum[1]) ? sum[0] : sum[1];
        ans = p / q * 100;
        printf("%.2f %%\n", ans);
    }
    return 0;
}
