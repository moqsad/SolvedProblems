#include "stdio.h"
#define SZ 500010

long long arr[500010], temp[500010], total;

void Merge(long long *arr, long long left, long long mid, long long right)
{
    long long pos, lpos, rpos, x, y;

    pos = 0;
    lpos = left;
    rpos = mid + 1;

    x = mid - left + 1;

    while(lpos <= mid && rpos <= right)
    {
        if(arr[lpos] <= arr[rpos])
        {
            temp[pos++] = arr[lpos++];
            --x;
        }
        else
        {
            temp[pos++] = arr[rpos++];
            total += x;
        }
    }

    while(lpos <= mid)
        temp[pos++] = arr[lpos++];

    while(rpos <= right)
        temp[pos++] = arr[rpos++];

    long long i;

    for(i=0; i<pos; i++)
        arr[left+i] = temp[i];

    return ;
}

void MergeSort(long long *arr, long long left, long long right)
{
    long long mid = (left + right) >> 1;

    if(left < right)
    {
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }

    return ;
}

int main()
{
    long long i, n;

    while(scanf("%lld",&n) == 1)
    {
        if(n == 0)
            break;
        for(i=0; i<n; i++)
            scanf("%lld",&arr[i]);
        MergeSort(arr, 0, n-1);
        printf("%lld\n", total);
        total = 0;
    }

    return 0;
}

