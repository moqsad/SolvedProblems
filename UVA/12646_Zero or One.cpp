#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

int arr[2];

int main()
{
    int a, b, c;
    char ch[2];
    while(scanf("%d %d %d", &a, &b, &c) == 3)
    {
        ++arr[a];
        ch[a] = 'A';
        ++arr[b];
        ch[b] = 'B';
        ++arr[c];
        ch[c] = 'C';
        if(arr[0] == 1)
            printf("%c\n", ch[0]);
        else if(arr[1] == 1)
            printf("%c\n", ch[1]);
        else
            printf("*\n");
        arr[0] = arr[1] = 0;
    }
    return 0;
}
