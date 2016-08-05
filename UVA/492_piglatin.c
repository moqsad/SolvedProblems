#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int count, tag, x, y;
    char letter[1200000];
    while(gets(letter))
    {
        tag = strlen(letter);
        count = 0;
        while(count <tag)
        {
            x = toupper(letter[count]);
            if(!(x >= 65 && x <= 90))
            {
                putchar(letter[count]);
                ++count;
            }
            else if(x == 65 || x == 69 || x == 73 || x == 79 || x == 85)
                while(x >= 65 && x <= 90)
                {
                    putchar(letter[count]);
                    ++count;
                    x = toupper(letter[count]);
                    if(!(x >= 65 && x <= 90))
                        printf("ay");
                }
            else if(x >= 65 && x <= 90)
            {
                y = count;
                while(x >= 65 && x <= 90)
                {
                    x = toupper(letter[count + 1]);
                    if(x >= 65 && x <= 90)
                        putchar(letter[count + 1]);
                    ++count;
                    if(!(x >= 65 && x <= 90))
                        printf("%cay", letter[y]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
