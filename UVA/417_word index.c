#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, l, m, det = 0;
    char arr[90000][10], letter[10], ch;
    for(i = 0; i < 26; ++i)
    {
        ++det;
        arr[det][0] = 97 + i;
        arr[det][1] = '\0';
    }
    for(i = 0; i < 26; ++i)
        for(j = i + 1; j < 26; ++j)
        {
            ++det;
            arr[det][0] = 97 + i;
            arr[det][1] = 97 + j;
            arr[det][2] = '\0';
        }
    for(i = 0; i < 26; ++i)
        for(j = i + 1; j < 26; ++j)
            for(k = j + 1; k < 26; ++k)
            {
                ++det;
                arr[det][0] = 97 + i;
                arr[det][1] = 97 + j;
                arr[det][2] = 97 + k;
                arr[det][3] = '\0';
            }
    for(i = 0; i < 26; ++i)
        for(j = i + 1; j < 26; ++j)
            for(k = j + 1; k < 26; ++k)
                for(l = k + 1; l < 26; ++l)
                {
                    ++det;
                    arr[det][0] = 97 + i;
                    arr[det][1] = 97 + j;
                    arr[det][2] = 97 + k;
                    arr[det][3] = 97 + l;
                    arr[det][4] = '\0';
                }
    for(i = 0; i < 26; ++i)
        for(j = i + 1; j < 26; ++j)
            for(k = j + 1; k < 26; ++k)
                for(l = k + 1; l < 26; ++l)
                    for(m = l + 1; m < 26; ++m)
                    {
                        ++det;
                        arr[det][0] = 97 + i;
                        arr[det][1] = 97 + j;
                        arr[det][2] = 97 + k;
                        arr[det][3] = 97 + l;
                        arr[det][4] = 97 + m;
                        arr[det][5] = '\0';
                    }
    while(scanf("%s", letter) == 1)
    {
        j = strlen(letter);
        ch = letter[0];
        k = 0;
        for(i = 1; i < j; ++i)
        {
            if(ch >= letter[i])
            {
                k = 1;
                break;
            }
            ch = letter[i];
        }
        if(k == 1)
            printf("0\n");
        else
        {
            for(l = 1; l <= det; ++l)
            {
                if(strcmp(arr[l], letter) == 0)
                {
                    printf("%d\n", l);
                    break;
                }
            }
        }
    }
    return 0;
}
