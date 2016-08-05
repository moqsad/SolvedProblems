#include <stdio.h>
int main()
{
    int a, letter[100], count = 0, x, sum, rest;
    do
    {
        scanf("%d", &letter[count]);
    }
    while(letter[count++] != 0);
    printf("PERFECTION OUTPUT\n");
    rest = count - 1;
    for(count = 0; count < rest; ++count)
    {
        a = letter[count];
        sum = 0;
        for(x = 1; x < a; ++x)
            if(a % x == 0)
                sum += x;
        if(sum == a)
            printf("%5d  PERFECT\n", a);
        else if(sum > a)
            printf("%5d  ABUNDANT\n", a);
        else
            printf("%5d  DEFICIENT\n", a);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
