#include <cstdio>
#include <cstring>
using namespace std;

double arr[100010];

int main()
{
    int t, cnt, n, i;
    double j = 1.0;
    arr[0] = 0;
    for(i = 1; i <= 100000; ++i)
    {
            arr[i] = arr[i - 1] + 1.0 / j;
    }

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        printf("Case %d: %.10lf\n", cnt, arr[n]);
    }
    return 0;
}
