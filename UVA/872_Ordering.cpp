#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <char, int> mm;

vector <int> edge[25];
vector <int> result;

char arr[30], letter[500];

int j, taken[25], cycle;

void visit(int x)
{
    if(taken[x] == 2 || cycle)
        return;
    if(taken[x] == 1)
    {
        cycle = 1;
        return;
    }
    int i, y;
    y = edge[x].size();
    taken[x] = 1;
    for(i = 0; i < y; ++i)
        visit(edge[x][i]);
    taken[x] = 2;
}

void backtrack(void)
{
    int i, k, l, x, y, p;
    if(result.size() == j)
    {
        printf("%c", arr[result[0]]);
        for(i = 1; i < j; ++i)
            printf(" %c", arr[result[i]]);
        printf("\n");
        return;
    }

    for(i = 0; i < j; ++i)
    {
        if(taken[i] == 0)
        {
            x = edge[i].size();
            p = 1;
            y = result.size();
//            printf("x : %d", x);

            for(k = 0; k < x; ++k)
            {
                p = 0;
                for(l = 0; l < y; ++l)
                {
                    if(result[l] == edge[i][k])
                    {
                        p = 1;
                        break;
                    }
                }
                if(p == 0)
                    break;
            }
//            printf("p : %d_____%d_____\n", p, result.size());

            if(p == 1)
            {
                taken[i] = 1;
                result.push_back(i);
//                printf("%d___\n", result.size());
                backtrack();
                taken[i] = 0;
                result.pop_back();
            }
        }
    }
}

int main()
{
    int t, cnt, i, x;
    scanf("%d", &t);
    getchar();
    for(cnt = 1; cnt <= t; ++cnt)
    {
        j = 0;
        getchar();
        gets(arr);
        x = strlen(arr);
        for(i = 0; i < x; i += 2)
            arr[j++] = arr[i];
        sort(arr, arr + j);
        for(i = 0; i < j; ++i)
            mm[arr[i]] = i;
        gets(letter);
        x = strlen(letter);
        for(i = 0; i < x; i += 4)
        {
            edge[mm[letter[i+2]]].push_back(mm[letter[i]]);
        }

        cycle = 0;
        for(i = 0; i < j; ++i)
        {
            visit(i);
            if(cycle == 1)
            {
                printf("NO\n");
                break;
            }
        }
//        printf("%d>>>>>>>>>>>>>>>>>>\n", j);
        memset(taken, 0, sizeof(taken));
        if(cycle == 0)
        {
            backtrack();
        }
        mm.clear();
        if(cnt < t)
            printf("\n");
        for(i = 0; i < j; ++i)
            edge[i].clear();
    }
    return 0;
}
/*
A B C
A<C C<A
*/
