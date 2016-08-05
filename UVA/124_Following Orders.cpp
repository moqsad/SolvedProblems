#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <char, int> mm;

vector <int> edge[25];
vector <int> result;

char arr[30], letter[500];

int j, taken[25];

void backtrack(void)
{
    int i, k, l, x, y, p;
    if(result.size() == j)
    {
        for(i = 0; i < j; ++i)
            printf("%c", arr[result[i]]);
        printf("\n");
        return;
    }

    for(i = 0; i < j; ++i)
    {
        if(taken[i] == 0)
        {
            x = edge[i].size();
            p = 1;
            y = result.size();

            for(k = 0; k < x; ++k)
            {
                p = 0;
                for(l = 0; l < y; ++l)
                {
                    if(result[l] == edge[i][k])
                    {
                        p = 1;
                        break;
                    }
                }
                if(p == 0)
                    break;
            }

            if(p == 1)
            {
                taken[i] = 1;
                result.push_back(i);
                backtrack();
                taken[i] = 0;
                result.pop_back();
            }
        }
    }
}

int main()
{
    int cnt = 0, i, x;
    while(gets(arr))
    {
        j = 0;
        x = strlen(arr);
        for(i = 0; i < x; i += 2)
            arr[j++] = arr[i];
        sort(arr, arr + j);
        for(i = 0; i < j; ++i)
            mm[arr[i]] = i;
        gets(letter);
        x = strlen(letter);
        for(i = 0; i < x; i += 4)
        {
            edge[mm[letter[i+2]]].push_back(mm[letter[i]]);
        }

        if(cnt > 0)
            printf("\n");
        backtrack();
//        mm.clear();
        for(i = 0; i < j; ++i)
            edge[i].clear();
        ++cnt;
    }
    return 0;
}


