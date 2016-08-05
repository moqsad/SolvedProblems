#include <cstdio>
#include <cstring>
#include <cctype>

char arr[210], letter[210];
int num[95];
bool visit[95];

int main()
{
    int ans, i, j, k, x, y, z;
    num['W'] = 1, num['H'] = 2, num['Q'] = 4, num['E'] = 8, num['S'] = 16, num['T'] = 32, num['X'] = 64;
    while(scanf("%s", arr) == 1)
    {
        if(arr[0] == '*')
            break;
        x = strlen(arr);
        ans = 0;
        for(i = 0; i < x; ++i)
        {
            if(isalpha(arr[i]))
            {
//                visit['W'] = visit['H'] = visit['Q'] = visit['E'] = visit['S'] = visit['T'] = visit['X'] = 0;
                memset(visit, 0, sizeof(visit));
                y = 1;
                j = 0;
                while(isalpha(arr[i]))
                {
                    if(visit[arr[i]] == 0)
                    {
                        visit[arr[i]] = 1;
                        y *= num[arr[i]];
                    }
                    letter[j++] = arr[i++];
                }
                z = 0;
                for(k = 0; k < j; ++k)
                {
                    z += y / num[letter[k]];
                }
                if(y == z)
                    ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
