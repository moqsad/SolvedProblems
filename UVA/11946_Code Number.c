#include <stdio.h>
int main()
{
    int count, t, i;
    char arr[10000], a1[] = "OIZEASGTBP";
    scanf("%d\n", &t);
        while(gets(arr))
        {
        for(i = 0; arr[i] != '\0'; ++i)
        {
            if(arr[i] >= '0' && arr[i] <= '9')
                putchar(a1[arr[i] - 48]);
            else
                putchar(arr[i]);
        }
        printf("\n");
        }
    return 0;
}
