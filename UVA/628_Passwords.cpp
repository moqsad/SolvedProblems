#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int x, k;

char word[150][300], rule[300];

vector <int> result;

void call(void)
{
    int i, j, y;
    if(result.size() == x)
    {
        j = 0;
        y = strlen(rule);
        for(i = 0; i < y; ++i)
        {
            if(rule[i] == '#')
                printf("%s", word[k]);
            else
                printf("%d", result[j++]);
        }
        printf("\n");
        return ;
    }
//    printf("++++++++++++\n");

    for(i = 0; i < 10; ++i)
    {
        result.push_back(i);
        call();
        result.pop_back();
    }
}

int main()
{
    int i, n, m, j, y;
    while(scanf("%d", &n) == 1)
    {
        for(i = 0; i < n; ++i)
            scanf("%s", word[i]);
        scanf("%d", &m);
        printf("--\n");
        for(i = 0; i < m; ++i)
        {
            scanf("%s", rule);
            y = strlen(rule);
            x = 0;
            for(j = 0; j < y; ++j)
            {
                if(rule[j] == '0')
                  ++x;
            }
            for(k = 0; k < n; ++k)
                call();
        }
    }
    return 0;
}
