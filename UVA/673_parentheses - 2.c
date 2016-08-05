#include <stdio.h>
#include <string.h>

int top, i, p;
char arr[200], det[200];

void push(void);
void pop(void);

int main()
{
    int n, x, cnt;
    scanf("%d", &n);
    getchar();
    for(cnt = 0; cnt < n; ++cnt)
    {
        top = 0;
        p = 1;
        gets(arr);
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
            if(arr[i] == '(' || arr[i] == '[')
                push();
            else
                pop();
            if(p == 0)
                break;
        }
        if(top > 0)
            p = 0;
        if(p == 1)
            printf("Yes\n");
        else
            printf("No\n");
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
    if(top > 0)
    {
        if(arr[i] == ')' && det[--top] != '(')
            p = 0;
        else if(arr[i] == ']' && det[--top] != '[')
            p = 0;
    }
    else
        p = 0;
    return;
}
