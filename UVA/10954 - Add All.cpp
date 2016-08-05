#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int arr[100000];

priority_queue <int> q;

int main()
{
    int n, x, y, a, cnt, i, sum, z;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
            sum = 0;
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%d", &a);
            a = -a;
            q.push(a);
        }
        while(q.size() > 1)
        {
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            z = x + y;
            sum += z;
            q.push(z);
        }
        q.pop();
        printf("%d\n", -sum);
    }
    return 0;
}
