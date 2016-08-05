#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
long long arr[1000000], L[1000000], index[1000000];
char letter[25];
int main()
{
    long long i, j, low, high, mid, Lislength, x, y, k, t, cnt;
    scanf("%d", &t);
    getchar();
    getchar();

    for(cnt = 1; cnt <= t; ++cnt)
    {
        i = 1;
        while(gets(letter))
        {
            if(letter[0] == '\0')
                break;
            arr[i++] = atol(letter);
        }
        index[0] = -10000000000000000;
//        for(j = 1; j < i; ++j)
//            index[j] = 10000000000000000;
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

        printf("Max hits: %lld\n", Lislength);
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

            if(cnt < t)
                printf("\n");
    }
    return 0;
}


