#include <stdio.h>
#include <string.h>
int main()
{
    int count = 0, i, j, ans[1000], p, q, x, det;
    char a1[1050][15], a2[1050][30], ch[15];
    while(gets(a1[count]))
    {
        if(a1[count][0] == '#' && strlen(a1[count]) == 1)
            break;
        ++count;
    }
    p = count;
    count = 0;
    while(gets(a2[count]))
    {
        if(a2[count][0] == '#' && strlen(a2[count]) == 1)
        break;
        i = 0;
        j = 0;
        while(a2[count][i] != '\0')
        {
        if(a2[count][i] != ' ')
        a2[count][j++] = a2[count][i];
        ++i;
        }
        a2[count][j] = '\0';
        ++count;
    }
    q = count;
    for(count = 0; count < q; ++count)
    ans[count] = 0;
    for(count = 0; count < q; ++count)
    {
        for(i = 0; i < p; ++i)
        {
            strcpy(ch, a2[count]);
            for(j = 0; j < strlen(a1[i]); ++j)
            {
                det = 0;
                for(x = 0; x < strlen(a2[count]); ++x)
                if(a1[i][j] == a2[count][x])
                {
                    a2[count][x] = '*';
                    det = 1;
                    break;
                }
                if(det == 0)
                break;
            }
            if(det == 1)
            ++ans[count];
            strcpy(a2[count], ch);
        }
    }
    for(count = 0; count < q; ++count)
    printf("%d\n", ans[count]);
return 0;
}
