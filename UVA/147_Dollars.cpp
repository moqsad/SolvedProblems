#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    long long int dp[30010], i, j, n, m, x, coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    char arr[10];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(i = 0; i < 11; ++i)
        for(j = coin[i]; j <= 30000; ++j)
            dp[j] += dp[j - coin[i]];
    n = 0;
    m = 0;
    while(scanf("%s", arr) == 1)
    {
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
            if(arr[i] != '.')
                n = n * 10 + arr[i] - 48;
            else
                break;
        }
        for(j = i + 1; j < x; ++j)
        {
            m = m * 10 + arr[j] - 48;
        }
        n *= 100;
        n += m;
        if(n == 0)
            break;
        printf("%6s%17lld\n", arr, dp[n]);
        n = 0;
        m = 0;
    }
    return 0;
}
