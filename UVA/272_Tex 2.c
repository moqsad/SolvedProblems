#include <stdio.h>
int main()
{
    int count, i = 0;
    char ch;
    while((ch = getchar()) != EOF)
    {
        if(ch == '"')
        {
            ++i;
            if(i % 2 == 1)
            printf("``");
            else
            printf("''");
        }
        else
        putchar(ch);
    }
    return 0;
}
