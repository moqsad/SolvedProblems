#include <cstdio>
int main()
{
    int s, f, sec, t, ans;
    while(scanf("%d %d %d %d", &s, &f, &sec, &t) == 4)
    {
        if(!(s == 0 && f == 0 && sec == 0 && t == 0))
        {
            ans = 120;
            if(s > f)
                ans += s - f;
            else
                ans += s - f + 40;
            if(sec > f)
                ans += sec - f;
            else
                ans += sec - f + 40;
            if(sec > t)
                ans += sec - t;
            else
                ans += sec - t + 40;
            printf("%d\n", ans * 9);
        }
        else
            break;
    }
    return 0;
}
