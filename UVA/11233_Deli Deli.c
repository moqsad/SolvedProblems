#include <stdio.h>
#include <string.h>
int main()
{
    int cnt, a, b, p, i;
    char irr[110][25], plu[110][25], word[110][25], x, y, z;
    scanf("%d %d", &a, &b);
    for(cnt = 0; cnt < a; ++cnt)
    {
        scanf("%s %s", irr[cnt], plu[cnt]);
    }
    for(cnt = 0; cnt < b; ++cnt)
    {
        scanf("%s", word[cnt]);
    }
    for(cnt = 0; cnt < b; ++cnt)
    {
        for(i = 0; i < a; ++i)
        {
            p = 0;
            if(strcmp(word[cnt], irr[i]) == 0)
            {
                printf("%s\n", plu[i]);
                p = 1;
                break;
            }
        }
        if(p == 0)
        {
            z = strlen(word[cnt]);
            x = word[cnt][z - 1];
            y = word[cnt][z - 2];
            if(x == 'y' && (!(y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u')))
            {
                word[cnt][z - 1] = '\0';
                printf("%sies\n", word[cnt]);
            }
            else if(x == 'o' || x == 'x' || x == 's' || (x == 'h' && y == 'c') || (x == 'h' && y == 's'))
            printf("%ses\n", word[cnt]);
            else
                printf("%ss\n", word[cnt]);
        }
    }
    return 0;
}
