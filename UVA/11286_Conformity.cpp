#include "bits/stdc++.h"
using namespace std;

map <string, int> mm;

int main()
{
    int num[10050], i, j, k, x, y, t, cnt, rm[5];
    char letter[25], math[10][10];
    while(scanf("%d", &t) == 1)
    {
        if(t == 0)
            break;
        k = 0;
        y = 0;
        memset(num, 0, sizeof(num));
        mm.clear();
        getchar();
        for(cnt = 0; cnt < t; ++cnt)
        {
            gets(letter);
            sscanf(letter, "%s %s %s %s %s", math[0], math[1], math[2], math[3], math[4]);
            for(i = 0; i < 5; ++i)
                rm[i] = atoi(math[i]);
            sort(rm, rm + 5);
            j = 0;
            for(i = 0; i < 5; ++i)
            {
                letter[j++] = rm[i] / 100 + 48;
                letter[j++] = (rm[i] / 10) % 10 + 48;
                letter[j++] = rm[i] % 10 + 48;
                letter[j++] = ' ';
            }
            letter[j - 1] = '\0';
            if(mm.find(letter) == mm.end())
            {
                mm[letter] = k++;
            }
            else
            {
                ++num[mm[letter]];
                if(num[mm[letter]] > y)
                    y = num[mm[letter]];
            }
        }
        j = 0;
        for(cnt = 0; cnt < k; ++cnt)
        {
            if(num[cnt] == y)
                ++j;
        }
        printf("%d\n", j * (y + 1));
    }
    return 0;
}
