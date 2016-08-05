#include <cstdio>
#include <cmath>

int prime[6000000];
bool arr[100000010];


int binary_search_(int x)
{
    int beg, endd, mid;
    beg = 1;
    endd = 5761456; // jotogula prime 100000010 porjonto ace......
    mid = (beg + endd) / 2;
    while(beg < endd)
    {
        if(prime[mid] > x)
            endd = mid - 1;
        else if(prime[mid] < x)
            beg = mid + 1;
        else
            return mid;
        mid = (beg +  endd) / 2;
    }
    return endd; // n / 2 er kacakaci je prime ta ace tar index
}

int main()
{
    int i, j, k, x, y, cnt = 2, n, p;
    prime[1] = 2;
    for(i = 4; i < 100000010; i += 2)
        arr[i] = 1;
    for(i = 3; i < 10002; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 100000010; j += k)
                arr[j] = 1;
        }
    }

    for(i = i; i < 100000010; i += 2)
        if(arr[i] == 0)
            prime[cnt++] = i;

//    printf("%d\n", cnt);

    while(scanf("%d", &n) == 1)
    {
        if(n > 0 && n < 4)
        {
            printf("%d is not the sum of two primes!\n", n);
        }
        else
        {
            p = 0;
            if(n % 2 == 0)
            {
                y = binary_search_(n / 2);
                p = 0;
                for(i = y; i > 0; --i)
                {
                    x = n - prime[i];
                    if(prime[i] != x && arr[x] == 0)
                    {
                        if(prime[i] < x)
                        {
                            y = x;
                            x = prime[i];
                        }
                        else
                        {
                            x = x;
                            y = prime[i];
                        }
                        printf("%d is the sum of %d and %d.\n", n, x, y);
                        p = 1;
                        break;
                    }
                }
            }
            else
            {
                if(arr[n - 2] == 0)
                {
                    printf("%d is the sum of 2 and %d.\n", n, n - 2);
                    p = 1;
                }
            }
            if(p == 0)
                printf("%d is not the sum of two primes!\n", n);
        }
    }
    return 0;
}
