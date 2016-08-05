#include <cstdio>
#include <iostream>
using namespace std;
long long arr[1000000], L[1000000], index[1000000];
int main()
{
    long long i = 0, j, low, high, mid, Lislength, x, y, k;
    while(scanf("%lld", &arr[++i]) == 1);

//    printf("%d________\n", i);


    index[0] = -10000000;
    for(j = 1; j < i; ++j)
        index[j] = 10000000;
    Lislength = 0;
    for(j = 1; j < i; j++)
    {
        low = 0;
        high = Lislength;
        while( low <= high )
        {
            mid = ( low + high ) / 2;
            if(index[mid] < arr[j])
                low = mid + 1;
            else
                high = mid - 1;
        }

        L[j] = low;
        index[low] = arr[j];
        if( Lislength < low )
            Lislength = low;
    }

    printf("%lld\n-\n", Lislength);
    x = 100000000000000000;
    k = 0;
    for(j = i - 1; j > 0; --j)
    {
        if(arr[j] < x && L[j] == Lislength)
        {
            index[k++] = arr[j];
            x = arr[j];
            --Lislength;
            if(Lislength == 0)
                break;
        }
    }

    for(j = k - 1; j >= 0; --j)
        printf("%lld\n", index[j]);
    return 0;
}

