#include <stdio.h>
#include <string.h>

int main()
{
    char ar[10000];
    int word = 0, i, a, j;
    while(gets(ar))
    {
        a = strlen(ar);
        word = 0;
        for(i = 0, j = 1; i < a; j++, i++)
        {
            if(((ar[i] >= 'A' && ar[i] <= 'Z')|| (ar[i] >= 'a' && ar[i] <= 'z')) && (ar[j]== '\0' || ar[j] == ' ' || ar[j] == '!' || ar[j] == '.' || ar[j] == ','))
            {
                ++word;
            }

        }
        printf("%d\n", word);
    }
    return 0;
}
