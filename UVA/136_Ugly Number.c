#include <stdio.h>
int main()
{
    long long int cnt, i, k;
    cnt = 6;
    i = 7;
    k = i;
    while(cnt != 1500)
    {
        while(i != 1)
        {
            if(i % 2 == 0)
                i /= 2;
            else if(i % 3 == 0)
                i /= 3;
            else if(i % 5 == 0)
                i /= 5;
            else
                break;
        }
        if(i == 1)
        {
            ++cnt;
            printf("%3lld    %3lld\n", k, cnt);
        }
        ++k;
        i = k;
    }
    return 0;
}
