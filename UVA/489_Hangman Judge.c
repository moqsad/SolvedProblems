#include <stdio.h>
#include <string.h>
int main()
{
    int a, cnt, i, j, k, x, y, p, l, fault, det, jjj, z;
    char ans[1500], guess[1000], match[30], wrong[30];
    while(1)
    {
        l = 0;
        det = 0;
        i = 0;
        fault = 0;
        scanf("%d", &a);
        if(a == -1)
            break;
        scanf("%s %s", ans, guess);
        x = strlen(ans);
        y = strlen(guess);
        for(cnt = 0; cnt < y; ++cnt)
        {

            p = 0;
            for(j = 0; j < i; ++j)
            {
                if(guess[cnt] == match[j])
                {
                    p = 1;
                    break;
                }
            }
            if(p == 1)
                continue;
            for(j = 0; j < x; ++j)
            {
                if(guess[cnt] == ans[j])
                {
                    match[i++] = guess[cnt];
                    p = 1;
                    break;
                }
            }
            for(jjj = 0; jjj < x; ++jjj)
            {
                z = 0;
                for(j = 0; j < i; ++j)
                {
                    if(ans[jjj] == match[j])
                    {
                        z = 1;
                        break;
                    }
                }
                if(z == 0)
                    break;
            }
            if(z == 1)
            {
                det = 1;
                printf("Round %d\nYou win.\n", a);
                break;
            }
            if(p == 0)
            {
                for(j = 0; j < l; ++j)
                {
                    if(guess[cnt] == wrong[j])
                    {
                        p = 1;
                        break;
                    }
                }
                if(p == 0)
                {
                    ++fault;
                    wrong[l++] = guess[cnt];
                    if(fault == 7)
                    {
                        det = 1;
                        printf("Round %d\nYou lose.\n", a);
                        break;
                    }
                }
            }
        }
        if(det == 0)
        {
            printf("Round %d\nYou chickened out.\n", a);
        }
    }
    return 0;
}
