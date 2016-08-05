#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

map <string, int> mm;

int main()
{
    int i, j, k, l, x, y, ans, p, z;
    char arr[110], letter[110];
    while(scanf("%s", arr) == 1)
    {
        x = strlen(arr);
        ans = 0;

        for(i = 0; i < x; ++i)
        {
            letter[0] = arr[i];
            letter[1] = '\0';
            if(mm.find(letter) == mm.end())
            {
                mm[letter] = 1;
                ++ans;
            }
//            printf("%d____________\n", ans);

            for(j = i + 1; j < x; ++j)
            {
                l = 0;
                z = j;
                y = (i + j) / 2;
                p = 1;
                for(k = i; k <= y; ++k)
                {
                    if(arr[z--] != arr[k])
                    {
                        p = 0;
                        break;
                    }
                    letter[l++] = arr[k];
                }

                if(p == 1)
                {
                    for(k = k; k <= j; ++k)
                    {
                        letter[l++] = arr[k];
                    }
                    letter[l] = '\0';

                    if(mm.find(letter) == mm.end())
                    {
                        mm[letter] = 1;
                        ++ans;
                    }
                }
            }
//            printf("%d____________\n", ans);
        }

        printf("The string '%s' contains %d palindromes.\n", arr, ans);
        mm.clear();
    }
    return 0;
}
