#include <cstdio>

int ans;

int main()
{
    int t, cnt;
    double l, wi, d, we;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lf %lf %lf %lf", &l, &wi, &d, &we);
        if(((l <= 56 && wi <= 45 && d <= 25) || l + wi + d <= 125) && we <= 7)
        {
            printf("1\n");
            ++ans;
        }
        else
            printf("0\n");
    }
    printf("%d\n", ans);
    return 0;
}
