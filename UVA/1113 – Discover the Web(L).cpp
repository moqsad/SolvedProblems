#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
    int cnt, t;
    char arr[10], in[60];
    string current;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        printf("Case %d:\n", cnt);
        stack <string> B;
        stack <string> F;
        current = "http://www.lightoj.com/";
        scanf("%s", arr);
        while(strcmp(arr, "QUIT") != 0)
        {
            if(strcmp(arr, "VISIT") == 0)
            {
                scanf("%s", in);
                B.push(current);
                while(!F.empty())
                    F.pop();
                current = in;
                printf("%s\n", in);
            }

            else if(strcmp(arr, "BACK") == 0)
            {
                if(B.empty())
                    printf("Ignored\n");
                else
                {
                    F.push(current);
                    cout << B.top() << endl;
                    current = B.top();
                    B.pop();
                }
            }

            else
            {
                if(F.empty())
                    printf("Ignored\n");
                else
                {
                    B.push(current);
                    cout << F.top() << endl;
                    current = F.top();
                    F.pop();
                }
            }
            scanf("%s", arr);
        }
    }
    return 0;
}
