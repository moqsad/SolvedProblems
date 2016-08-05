#include <stdio.h>
int main()
{
    int a, count, sum = 0;
    while(1){
    scanf("%d", &a);
    if(a == 0)
    break;
    sum = 0;
    for(count = 1; count <= a; ++count)
        sum += count * count;
    printf("%d\n", sum);
    }
    return 0;
}
