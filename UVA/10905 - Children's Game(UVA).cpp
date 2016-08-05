#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

string arr[60];

int main()
{
    int n, i, j;
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 0; i < n; ++i)
            cin >> arr[i];

        for(i = 0; i < n; ++i)
            for(j = i + 1; j < n; ++j)
            {
                if(arr[i] + arr[j] < arr[j] + arr[i])
                    swap(arr[i], arr[j]);
            }

        for(i = 0; i < n; ++i)
            cout << arr[i];

        cout << "\n";
    }
    return 0;
}
