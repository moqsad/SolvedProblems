#include <cstdio>
#include <cstring>
using namespace std;

char num[100010], ans[100010];

int main()
{
    long long divisor, x, y, i, j;
    char ch;
    while(scanf("%s %c %lld", num, &ch, &divisor) == 3)
    {
        x = strlen(num);
        if(ch == '%')
        {
            y = 0;
            for(i = 0; i < x; ++i)
                y = ((y * 10) + num[i] - 48) % divisor;
            printf("%lld\n", y);
        }
        else
        {
            memset(ans, '0', sizeof(ans));
            y = 0;
            i = 0;
            while(y < divisor)
            {
                if(i == x)
                    break;
                y = y * 10 + num[i++] - 48;
            }
            j = 0;
            if(y >= divisor)
            {
                ans[j++] = y / divisor + 48;
                y = y % divisor;
            }
            for(i = i; i < x; ++i)
            {
                y = y * 10 + num[i] - 48;
                if(y >= divisor)
                {
                    ans[j] = y / divisor + 48;
                    y = y % divisor;
                }
                ++j;
            }
            if(j > 0)
            {
                ans[j] = '\0';
                printf("%s\n", ans);
            }
            else
                printf("0\n");
        }
    }
    return 0;
}
