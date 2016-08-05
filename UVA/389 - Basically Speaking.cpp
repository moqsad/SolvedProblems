#include <cstdio>
#include <map>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

map <char, int> mm;

int main()
{
//    cout << pow(3, 3) << "\n";
    int from, to, i = 0, j, x, y, total, arr[1000];
    char num[1000], ch;

    for(ch = '0'; ch <= '9'; ++ch)
        mm[ch] = i++;
    for(ch = 'A'; ch <= 'F'; ++ch)
        mm[ch] = i++;

    while(scanf("%s %d %d", num, &from, &to) == 3)
    {
        x = strlen(num);
        y = 1;
        total = 0;
        for(i = x - 1; i >= 0; --i)
        {
            total += y * mm[num[i]];
            y *= from;
        }

        i = 0;
        while(total > 0)
        {
            arr[i++] = total % to;
            total /= to;
        }

        if(i > 7)
            printf("  ERROR\n");
        else
        {
            j = 0;
            while(--i >= 0)
            {
                if(arr[i] < 10)
                    num[j++] = 48 + arr[i];
                else
                    num[j++] = 55 + arr[i];
            }
            num[j] = '\0';
            if(j > 0)
                printf("%7s\n", num);
            else
                printf("      0\n");
        }
    }
    return 0;
}

