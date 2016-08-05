#include <cstdio>
#include <map>
#include <set>
#include <iostream>
using namespace std;

set <string> myset;
set <string>::iterator it;

map <string, double> mm;

char arr[50];

int main()
{
    int cnt, t, i;
    double n;
    scanf("%d", &t);
    getchar();
    getchar();
    for(cnt = 1; cnt <= t; ++cnt)
    {
        n = 0;
        while(gets(arr))
        {
            if(arr[0] == '\0')
                break;
            ++n;
            if(mm.find(arr) == mm.end())
            {
                mm[arr] = 1;
            }
            else
                mm[arr] = mm[arr] + 1;
            myset.insert(arr);
        }

        for(it=myset.begin(); it!=myset.end(); it++)
        {
            cout << *it;
            printf(" %.4lf\n", mm[*it] / n * 100.00);
        }

        if(cnt < t)
            printf("\n");
        mm.clear();
        myset.clear();
    }
    return 0;
}

