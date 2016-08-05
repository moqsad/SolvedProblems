#include <cstdio>
#include <cstring>
#include <cstdlib>

int num[1010];
char letter[15], a[15];

int main()
{
    int n, cnt, sum, avg, i, j, x, y, sum2;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        getchar();
        sum = 0;
        for(cnt = 0; cnt < n; ++cnt)
        {
            j = 0;
            gets(letter);
            for(i = 0; letter[i] != '.' && letter[i] != '\0'; ++i)
                a[j++] = letter[i];
            a[j] = '\0';
            x = atoi(a);
            y = strlen(letter);
            j = 0;
            for(i = i + 1; i < y; ++i)
                a[j++] = letter[i];
            a[j] = '\0';
            x = x * 100 + atoi(a);
            num[cnt] = x;
            sum += x;
        }
        avg = sum / n;
        if(sum % n == 0)
        {
            sum = 0;
            for(cnt = 0; cnt < n; ++cnt)
                if(avg < num[cnt])
                    sum += num[cnt] - avg;
            printf("$%d.%02d\n", sum / 100, sum % 100);
        }
        else
        {
            sum2 = 0;
            sum = 0;
            x = avg;
            y = avg + 1;
            for(cnt = 0; cnt < n; ++cnt)
            {
                if(x >= num[cnt])
                    sum += x - num[cnt];
                else
                    sum2 += num[cnt] - y;
            }
            sum = sum > sum2 ? sum : sum2;
            printf("$%d.%02d\n", sum / 100, sum % 100);
        }
    }
    return 0;
}
