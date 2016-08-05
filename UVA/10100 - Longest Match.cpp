#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map <string, int> mm;

int ans[1010][1010], a[3][1010], p, l;
char arr[2010], letter[30];

int func(int index)
{
    int i, j, k, x;
    x = strlen(arr);
    if(x == 0)
        p = 0;
    k = 1;
    for(i = 0; i < x; ++i)
    {
        if(isalnum(arr[i]))
        {
            j = 0;

            while(isalnum(arr[i+1]))
            {
                letter[j++] = arr[i];
                ++i;
            }

            letter[j++] = arr[i];
            letter[j] = '\0';

            if(mm.find(letter) == mm.end())
                mm[letter] = ++l;
            a[index][k++] = mm[letter];
        }
    }
    return k;
}

int main()
{
    int u, v, i, j, cnt = 0;
    while(gets(arr))
    {
        p = 1;
        u = func(0);
        gets(arr);
        v = func(1);
        if(p == 1)
        {
            for(i = 1; i < v; ++i)
                for(j = 1; j < u; ++j)
                {
                    if(a[1][i] == a[0][j])
                        ans[i][j] = ans[i - 1][j - 1] + 1;
                    else if(ans[i - 1][j] > ans[i][j - 1])
                        ans[i][j] = ans[i - 1][j];
                    else
                        ans[i][j] = ans[i][j - 1];
                }
            printf("%2d. Length of longest match: %d\n", ++cnt, ans[i-1][j-1]);
        }

        else
            printf("%2d. Blank!\n", ++cnt);
    }
    return 0;
}
