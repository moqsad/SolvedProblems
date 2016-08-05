#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

map <char, char> mm;
char arr[2000010];

int main()
{
    int L, i, location, total, x;
    char ch;
    mm['D'] = 'R';
    mm['R'] = 'D';
    mm['0'] = '0';
    while(scanf("%d", &L) == 1)
    {
        if(L == 0)
            break;

        scanf("%s", arr);
        ch = '0';
        total = 1000000000;
        for(i = 0; i < L; ++i)
        {
            if(arr[i] == 'D' || arr[i] == 'R')
            {
                if(arr[i] == mm[ch])
                {
                    x = i - location;
                    if(x < total)
                    {
                        total = x;
                    }
                    location = i;
                    ch = arr[i];
                }

                else
                {
                    location = i;
                    ch = arr[i];
                }
            }
            else if(arr[i] == 'Z')
            {
                total = 0;
                break;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
