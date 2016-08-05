#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;

char arr[2000], part[22];
map <string, int> mm;

int main()
{
    int x, a, b, i, j, k, l, m;
    while(gets(arr))
    {
        mm.clear();
        x = strlen(arr);
        j = 0;
        k = 0;
        for(i = 0; i < x; ++i)
        {
            if(arr[i] != ' ')
            {
                while(arr[i] >= '0' && arr[i] <= '9')
                    part[j++] = arr[i++];
                part[j] = '\0';
                mm[part] = 1;
                ++k;
                j = 0;
            }
        }
        gets(arr);
        x = strlen(arr);
        j = 0;
        l = 0;
        m = 0;
        for(i = 0; i < x; ++i)
        {
            if(arr[i] != ' ')
            {
                while(arr[i] >= '0' && arr[i] <= '9')
                    part[j++] = arr[i++];
                part[j] = '\0';
                if(mm.find(part) != mm.end())
                    ++l;
                ++m;
                j = 0;
            }
        }
        if(k == l && l == m)
            printf("A equals B\n");
        else if(l == 0)
            printf("A and B are disjoint\n");
        else if(k > l && m > l)
            printf("I'm confused!\n");
        else if(k > l && m == l)
            printf("B is a proper subset of A\n");
        else
            printf("A is a proper subset of B\n");

    }
    return 0;
}
