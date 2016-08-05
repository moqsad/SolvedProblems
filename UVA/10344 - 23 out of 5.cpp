#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int p, arr[10];

bool taken[10];

vector <int> result;

void call(int sum, int j)
{
    int y, i, x, z;
    if(j == 5)
    {
        if(sum == 23)
            p = 1;
        return ;
    }

    ++j;
    for(i = 1; i < 6; ++i)
    {
        if(taken[i] == 0)
        {
            taken[i] = 1;
//            result.push_back(arr[i]);
            if(j > 1)
            {
                call(sum + arr[i], j);
                call(sum - arr[i], j);
                call(sum * arr[i], j);
            }
            else
                call(arr[i], j);
            if(p == 1)
                return;
            taken[i] = 0;
//            result.pop_back();
        }
    }
}

int main()
{
    int i;
    while(1)
    {
        for(i = 1; i < 6; ++i)
        {
            scanf("%d", &arr[i]);
            taken[i] = 0;
        }
        if(arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0 && arr[5] == 0)
            break;
        p = 0;
        call(0, 0);
        if(p == 1)
            printf("Possible\n");
        else
            printf("Impossible\n");
//        result.clear();
    }
    return 0;
}
