#include <cstdio>
#include <iostream>
using namespace std;
int arr[1000000], num[1000000], index[1000000];
int main()
{
    int i = 1, j, k, cnt = 0, low, high, mid, Lislength;
    while(scanf("%d", &num[i]) == 1)
    {
        if(num[i] == -1)
            break;
        while(scanf("%d", &num[++i]) == 1)
        {
            if(num[i] == -1)
                break;
        }
        k = 1;
        for(j = i - 1; j > 0; --j)
           arr[k++] = num[j];
        index[0] = -10000000;
        for(j = 1; j < i; ++j)
            index[j] = 10000000;
        Lislength = 0;
        for(j = 1; j < i; j++)
        {
            low = 0; // minimum position where we to put data in I[]
            high = Lislength; // the maximum position
            while( low <= high )   // binary search to find the correct position
            {
                mid = ( low + high ) / 2;
                if(index[mid] <= arr[j])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            // observe the binary search carefully, when the binary search ends
            // low > high and we put our item in I[low]
            index[low] = arr[j];
            if( Lislength < low ) // LisLength contains the maximum position
                Lislength = low;
        }
        if(cnt > 0)
            printf("\n");
        printf("Test #%d:\n", ++cnt);
        printf("  maximum possible interceptions: %d\n", Lislength);
        i = 1;
    }
    return 0;
}
