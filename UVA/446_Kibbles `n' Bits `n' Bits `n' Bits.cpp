#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

map <char, int> mm;

int main()
{
    int i, j, cnt, t, x, y, z;
    char arr[20] = "0123456789ABCDEF", a[20], b[20], ch;

    for(i = 0; i < 16; ++i)
        mm[arr[i]] = i;

    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%s %c %s", a, &ch, b);


        x = strlen(a);
        j = 1;
        y = 0;
        for(i = x - 1; i >= 0; --i)
        {
            y += mm[a[i]] * j;
            j *= 16;
        }
        x = y;
        for(i = 0; i < 13; ++i)
            a[i] = '0';
        a[i] = '\0';
        i = 12;
        while(x > 0)
        {
            a[i--] = x % 2 + 48;
            x /= 2;
        }


        x = strlen(b);
        j = 1;
        z = 0;
        for(i = x - 1; i >= 0; --i)
        {
            z += mm[b[i]] * j;
            j *= 16;
        }
        x = z;
        for(i = 0; i < 13; ++i)
            b[i] = '0';
        b[i] = '\0';
        i = 12;
        while(x > 0)
        {
            b[i--] = x % 2 + 48;
            x /= 2;
        }

        if(ch == '+')
        {
            printf("%s + %s = %d\n", a, b, y + z);
        }
        else
        {
            printf("%s - %s = %d\n", a, b, y - z);
        }
    }
    return 0;
}
