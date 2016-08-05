#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int arr[10050], b, i = 0, j;
    while(scanf("%d", &arr[i++]) == 1)
    {
        b = i;
    int num[b];
    for(j = 0; j < b; ++j)
    {
        num[j] = arr[j];
    }
    qsort(num, b, sizeof(int), cmpfunc);
    b = b - 1;
    if(b % 2 == 0)
        printf("%d\n", num[b / 2]);
    else
        printf("%d\n", (num[b / 2] + num[b / 2 + 1]) / 2);
    }
    return 0;
}
