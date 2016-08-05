#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;

set <char> mm;
set <char> ::iterator it;

int r, value[200], uniq;
char arr[50], ans[50];

void backtrack(int pos, int indx, int num[])
{
    int i;
    if(indx == r)
    {
        ans[indx] = '\0';
        printf("%s\n", ans);
        return ;
    }

//    printf("%d>>>>>>>>>>>>>>>>>>>\n", indx);
    for(i = pos; i < uniq; ++i)
    {
        if(num[arr[i]] < value[arr[i]])
        {
            ++num[arr[i]];
            ans[indx] = arr[i];
//            printf("%c %d++++++++\n", ans[indx], indx);
            backtrack(i, indx + 1, num);
            --num[arr[i]];
        }
    }
}

int main()
{
    int i, num[200];
    while(scanf("%s %d", arr, &r) == 2)
    {
        memset(value, 0, sizeof(value));
        memset(num, 0, sizeof(num));
        for(i = 0; arr[i]; ++i)
        {
            mm.insert(arr[i]);
            ++value[arr[i]];
        }

        uniq = mm.size();

        i = 0;
        for(it = mm.begin(); it != mm.end(); it++)
            arr[i++] = *it;
//        arr[i] = '\0';
//        printf("%s______________\n", arr);
        backtrack(0, 0, num);
        mm.clear();
    }
    return 0;
}

