#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int arr[100000000];

map <int, int> m;

int main()
{
    int t, cnt, i, j, n, total, x;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        total = 0;
        m.clear();
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        j = 0;
        x = 0;
        for(i = 0; i < n; ++i)
        {
            if(m.find(arr[i]) == m.end() || m[arr[i]] == i)
            {
                //printf("++++++++\n");
                ++j;
                m[arr[i]] = i;
            }
            else if(m[arr[i]] >= x)
            {
                x = m[arr[i]];
                m[arr[i]] = i;
                i = x;
                //printf("%d %d %d******\n", x, m[arr[i]], i);
               // if(arr[i] == arr[i + 1])
                   // ++i;
                if(total < j)
                {
                    total = j;
                }
                j = 0;
            }
            else                               //jodi m[arr[i]] er last mapping x er chee choto hoi, tahole notun counting er starting er por ei numberti rippet hoi ni.
            {
                //printf("________\n");
                ++j;
                m[arr[i]] = i;
            }
        }
        if(j > total)
            total = j;
        printf("%d\n", total);
    }
    return 0;
}
