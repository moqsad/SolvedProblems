#include <stdio.h>
int main()
{
    int a, count, sum;
    while(1){
    scanf("%d", &a);
    if(a == 0)
    break;
    sum = a * (a + 1) * (2 * a + 1) / 6;
    printf("%d\n", sum);
    }
    return 0;
}

