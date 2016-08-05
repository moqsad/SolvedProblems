#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map <char, int> mm;
map <int, char> nn;

bool comp(char p, char q)
{
    return mm[p] < mm[q];
}

int main()
{
    char arr[510], ch;
    int flag[510];
    int t, cnt, x, i;
    scanf("%d", &t);

    i = 1;
    for(ch = 'A'; ch <= 'Z'; ++ch)
    {
        mm[ch] = i;
        nn[i] = ch;
        i += 2;
    }

    i = 2;
    for(ch = 'a'; ch <= 'z'; ++ch)
    {
        mm[ch] = i;
        nn[i] = ch;
        i += 2;
    }

    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%s", arr);
        x = strlen(arr);
        sort(arr, arr + x, comp);
        for(i = 0; i < x; ++i)
            flag[i] = mm[arr[i]];
        do
        {
            for(i = 0; i < x; ++i)
                printf("%c", nn[flag[i]]);
            printf("\n");
        }
        while(next_permutation(flag, flag + x));
    }

    return 0;
}
