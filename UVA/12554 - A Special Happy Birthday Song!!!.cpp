#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int i, j, n;
    char arr[][10] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday",
                      "to", "Rujia", "Happy", "birthday", "to", "you"
                     }, letter[110][110], small[20][110];
    scanf("%d", &n);
    if(n >= 16)
    {
        j = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%s", letter[i]);
            printf("%s: ", letter[i]);
            printf("%s\n", arr[j++]);
            if(j == 16)
                j = 0;
        }
        i = 0;
        for(j = j; j < 16; ++j)
        {
            printf("%s: ", letter[i++]);
            printf("%s\n", arr[j]);
        }
    }
    else
    {
        for(i = 0; i < n; ++i)
            scanf("%s", small[i]);
        j = 0;
        for(i = 0; i < 16; ++i)
        {
            printf("%s: ", small[j++]);
            if(j == n)
                j = 0;
            printf("%s\n", arr[i]);
        }
    }
    return 0;
}
