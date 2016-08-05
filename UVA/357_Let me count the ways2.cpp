#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long int arr[30060];
long long int coin[5] = {1, 5, 10, 25, 50};

int main()
{
    long long int i, j, amount;
    arr[0] = 1;
    for(i = 0; i < 5; ++i)
        for(j = 0; j < 30001; ++j)
        {
            arr[j + coin[i]] += arr[j];
        }
        while(scanf("%lld", &amount) == 1)
        {
            if(arr[amount] > 1)
            {
                printf("There are %lld ways to produce %lld cents change.\n", arr[amount], amount);
            }
            else
                printf("There is only 1 way to produce %lld cents change.\n", amount);
        }
        return 0;
}
