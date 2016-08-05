#include <stdio.h>
#include <ctype.h>
int main()
{
    int count, word;
    char string[100];
    while(scanf(" %[^\n]", &string) == 1)
    {
        word = 0;
        count = 0;
        while(string[count] != '\0')
        {
            if(toupper(string[count]) >= 'A' && toupper(string[count]) <= 'Z')
                while(toupper(string[count]) >= 'A' && toupper(string[count]) <= 'Z')
                {
                    ++count;
                    if(!(toupper(string[count]) >= 'A' && toupper(string[count]) <= 'Z'))
                        ++word;
                }
            else
                ++count;
        }
        printf("%d\n", word);
    }
    return 0;
}
