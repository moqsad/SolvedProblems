#include "bits/stdc++.h"
using namespace std;

map <char, int> mm;
map <char, int> nn;
map <int, int> gg;
map <int, int> hh;


int top, i, y, indicate, p;
char arr[2050], det[1500];

void push(void);
void pop(void);


int main()
{
    int n, a, b, cnt, x;
    char ch;
    scanf("%d", &n);

    for(cnt = 0; cnt < n; ++cnt)
    {
        scanf(" %c %d %d", &ch, &a, &b);
        mm[ch] = a;
        nn[ch] = b;
    }

    while(scanf("%s", arr) == 1)
    {
        y = 0;
        p = 0;
        indicate = 0;
        if(arr[0] != '(')
            printf("0\n");
        else
        {
            x = strlen(arr);
            for(i = 0; i < x; ++i)
            {
                if(indicate == 1)
                {
                    p = 1;
                    printf("error\n");
                    break;
                }
                if(arr[i] != ')')
                    push();
                else
                    pop();
            }
            if(indicate == 0)
                printf("%d\n", y);
            else if(p == 0)
                printf("error\n");

        }
    }
    return 0;
}

void push(void)
{
    det[top++] = arr[i];
    return;
}

void pop(void)
{
    int p, q, r, s;
        --top;
    if(det[top] != '0')
    {
        r = mm[det[top]];
        s = nn[det[top]];
    }
    else
    {
        r = gg[top];
        s = hh[top];
    }

    --top;
    if(det[top] != '0')
    {
        p = mm[det[top]];
        q = nn[det[top]];
    }
    else
    {
        p = gg[top];
        q = hh[top];
    }

    if(q != r)
    {
        indicate = 1;
        return;
    }
    y += p * q * s;
    --top;
    det[top] = '0';
    gg[top] = p;
    hh[top] = s;
    ++top;
    return;
}
/*
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))
*/
