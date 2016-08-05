#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int num[100], i = 0, x, y, cnt, z, n;
    char ch, arr[10], letter[10];
    letter[4] = '\0';
    for(ch = 'A'; ch <= 'Z'; ++ch)
        num[ch] = i++;
    scanf("%d", &n);
    for(cnt = 0; cnt < n; ++cnt)
    {
        scanf("%s", arr);
        x = num[arr[0]] * 676 + num[arr[1]] * 26 + num[arr[2]];
        letter[0] = arr[4], letter[1] = arr[5], letter[2] = arr[6], letter[3] = arr[7];
        y = atoi(letter);
        z = y - x;
        if(z > -101 && z < 101)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
