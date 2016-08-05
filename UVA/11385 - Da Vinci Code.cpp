#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

long long f[110], num[110];
char arr[210], letter[110];
map <long long, long long> mm;

int main()
{
    long long i, n, j, t, cnt, x, y, high;
    f[0] = 1;
    f[1] = 1;
    mm[1] = 1;
    i = 1;
    while(i < 48)
    {
        f[++i] = f[i - 1] + f[i - 2];
        mm[f[i]] = i;
    }
    scanf("%lld\n", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lld\n", &n);
        for(j = 0; j < n; ++j)
        {
            scanf("%lld", &num[j]);
        }
        getchar();
        gets(arr);
        x = strlen(arr);
        i = 0;
        high = 0;
        memset(letter, ' ', sizeof(letter));
        for(j = 0; j < x; ++j)
        {
            if(arr[j] >= 'A' && arr[j] <= 'Z')
            {
                y = mm[num[i]];
                if(y > high)
                    high = y;
                letter[y - 1] = arr[j];
                ++i;
                if(i == n)
                    break;
            }
        }
        letter[high] = '\0';
        printf("%s\n", letter);
    }
    return 0;
}
