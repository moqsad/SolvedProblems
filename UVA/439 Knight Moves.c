#include <stdio.h>

char arr[8][8], a1[5], a2[5];
int x, y, det;
int m[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int n[] = {2, 1, -1, -2, -2, -1, 1, 2};

int func(int a, int b, int cnt);

int main()
{
    int a, b, cnt;
    while(scanf("%s %s", a1, a2) == 2)
    {
        a = a1[0] - 96;
        b = a1[1] - 48;
        x = a2[0] - 96;
        y = a2[1] - 48;
        cnt = 0;
        det = 7;
        if(a == x && b == y)
            det = 0;
        else
        {
            cnt = 1;
            func(a, b, cnt);
        }
        printf("To get from %s to %s takes %d knight moves.\n", a1, a2, det);
    }
    return 0;
}

int func(int a, int b, int cnt)
{
    int p, u, v;
    if(det < cnt)
        return;
    if(a > 0 && a < 9 && b > 0 && b < 9)
    {
        for(p = 0; p < 8; ++p)
        {
            u = a + m[p];
            v = b + n[p];
            if(u == x && v == y)
            {
                if(det > cnt)
                    det = cnt;
                return;
            }
            func(u, v, cnt + 1);
        }
    }
    return;
}
