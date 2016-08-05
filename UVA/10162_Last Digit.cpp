#include <cstdio>
#include <cstring>

int main()
{
    int i, sum = 0, multi, j, arr[110];
    char letter[110];

    for(i = 1; i <= 101; ++i)
    {
        multi = i;
        for(j = 2; j <= i; ++j)
        {
            multi = (multi * i) % 100000;
        }
        sum = (sum + multi) % 100000;
        arr[i] = sum % 10;
    }
    while(scanf("%s", letter) == 1)
    {
        if(letter[0] == '0')
            break;
        sum = 0;
        j = strlen(letter);
        for(i = 0; i < j; ++i)
            sum = (sum * 10 + letter[i] - 48) % 100;
        if(sum == 0)
            sum = 100;
        printf("%d\n", arr[sum]);
    }
    return 0;
}
