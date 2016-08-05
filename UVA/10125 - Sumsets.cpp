#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map <int, int> ace, mm, nn;

int arr[1100];

int main()
{
    int n, i, j, k, p, x, y, z;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;

        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

            sort(arr, arr + i);

        k = 0;
        for(i = 0; i < n; ++i)
            for(j = i + 1; j < n; ++j)
            {
                ace[arr[i] + arr[j]] = ++k;
                mm[k] = arr[i];
                nn[k] = arr[j];
            }

        p = 0;
        for(i = n - 1; i >= 0; --i)
        {
            for(j = 0; j < n; ++j)
            {
                y = arr[i] - arr[j];
                if(ace.find(y) != ace.end())
                {
                    z = ace[y];
                    if(arr[j] != mm[z] && arr[j] != nn[z])
                    {
                        if(arr[i] != arr[j] && arr[i] != mm[z] && arr[i] != nn[z])
                        {
                            p = 1;
                            break;
                        }
//                        p = 1;
//                        break;
                    }
                }
            }

            if(p == 1)
                break;
        }

        if(p == 1)
            printf("%d\n", arr[i]);
        else
            printf("no solution\n");

        mm.clear();
        nn.clear();
        ace.clear();
    }
    return 0;
}

/*
3
0
-1
1
*/
