#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;

set <char> mm;
set <char> ::iterator it;

int uniq, col[200], m;
char ans[15], arr[15];

void backtrack(int indx)
{
    int i;
    if(indx == m)
    {
        ans[indx] = '\0';
        printf("%s\n", ans);
        return;
    }

    for(i = 0; i <  uniq; ++i)
    {
        if(col[arr[i]])
        {
            --col[arr[i]];
            ans[indx] = arr[i];
            backtrack(indx + 1);
            ++col[arr[i]];
        }
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", arr);
        m = strlen(arr);
        memset(col, 0, sizeof(col));
        for(i = 0; arr[i]; ++i)
        {
            mm.insert(arr[i]);
            col[arr[i]]++;
        }

        i = 0;
        for(it=mm.begin(); it!=mm.end(); it++)
            arr[i++] = *it;

        uniq = mm.size();

        backtrack(0);
        printf("\n");
        mm.clear();
    }
    return 0;
}

