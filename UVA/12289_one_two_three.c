#include <stdio.h>
#include  <string.h>
int main()
{
    int n, det, count, a, p;
    char arr[6], letter[6];
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%s", arr);
        det = strlen(arr);
        switch(det)
        {
        case 3 :
            a = 0;
            strcpy(letter, "one");
            for(p = 0; p < 3; ++p)
                if(arr[p] != letter[p])
                    ++a;
            if(a <= 1)
                printf("1\n");
            else
            {
                a = 0;
                strcpy(letter, "two");
                for(p = 0; p < 3; ++p)
                    if(arr[p] != letter[p])
                        ++a;
                if(a <= 1)
                    printf("2\n");
                else
                {
                    a = 0;
                    strcpy(letter, "six");
                    for(p = 0; p < 3; ++p)
                        if(arr[p] != letter[p])
                            ++a;
                    if(a <= 1)
                        printf("6\n");
                    else
                        printf("10\n");
                }
            }
            break;
        case 4 :
            a = 0;
            strcpy(letter, "four");
            for(p = 0; p < 4; ++p)
                if(arr[p] != letter[p])
                    ++a;
            if(a <= 1)
                printf("4\n");
            else
            {
                a = 0;
                strcpy(letter, "five");
                for(p = 0; p < 4; ++p)
                    if(arr[p] != letter[p])
                        ++a;
                if(a <= 1)
                    printf("5\n");
                else
                    printf("9\n");
            }
            break;
        case 5 :
            a = 0;
            strcpy(letter, "three");
            for(p = 0; p < 5; ++p)
                if(arr[p] != letter[p])
                    ++a;
            if(a <= 1)
                printf("3\n");
            else
            {
                a = 0;
                strcpy(letter, "seven");
                for(p = 0; p < 5; ++p)
                    if(arr[p] != letter[p])
                        ++a;
                if(a <= 1)
                    printf("5\n");
                else
                    printf("9\n");
            }
            break;
        }
    }
    return 0;
}
