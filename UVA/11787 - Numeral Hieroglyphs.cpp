#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

map <char, int> mm, nn;

char arr[505], letter[] = "BUSPFTM", ch;

int num[10];

int main()
{
    int p, cnt, t, i, x, sign, ans;
        mm['B'] = 1, mm['U'] = 10, mm['S'] = 100, mm['P'] = 1000, mm['F'] = 10000, mm['T'] = 100000, mm['M'] = 1000000;
    for(i = 0; i < 7; ++i)
        nn[letter[i]] = i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(num, 0, sizeof(num));
        p = 1;
        scanf("%s", arr);
        x = strlen(arr);
        ch = arr[0];
        ++num[nn[arr[0]]];

        for(i = 1; i < x; ++i)
        {
            ++num[nn[arr[i]]];
            if(num[nn[arr[i]]] == 10)
            {
                p = 0;
                break;
            }
            if(ch != arr[i])
                break;
        }

        if(i < x && p == 1)
        {
            if(nn[ch] < nn[arr[i]])
                sign = 1;
            else
                sign = 0;

            if(sign == 1)
                for(i = i + 1; i < x; ++i)
                {
                    ++num[nn[arr[i]]];
                    if(num[nn[arr[i]]] == 10)
                    {
                        p = 0;
                        break;
                    }
                    if(nn[arr[i-1]] > nn[arr[i]])
                    {
                        p = 0;
                        break;
                    }
                }

            else
                for(i = i + 1; i < x; ++i)
                {
                    ++num[nn[arr[i]]];
                    if(num[nn[arr[i]]] == 10)
                    {
                        p = 0;
                        break;
                    }
                    if(nn[arr[i-1]] < nn[arr[i]])
                    {
                        p = 0;
                        break;
                    }
                }
        }

        if(p == 0)
            printf("error\n");
        else
        {
            ans = 0;
            for(i = 0; i < 7; ++i)
                ans += num[i] * mm[letter[i]];
            printf("%d\n", ans);
        }
    }
    return 0;
}
