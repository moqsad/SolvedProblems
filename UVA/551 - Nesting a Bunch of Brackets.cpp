#include <cstdio>
#include <cstring>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

stack <char> s;
map <char, char> mm;

char arr[4000];

int main()
{
    int i, j, x, p;
    mm['}'] = '{';
    mm[']'] = '[';
    mm[')'] = '(';
    mm['>'] = '<';
    while(gets(arr))
    {
        p = 1;
        j = 1;
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
//            printf("%c__________\n", arr[i]);
            if(arr[i] == '{' || arr[i] == '[' || arr[i] == '<')
                s.push(arr[i]);

            else if(arr[i] == '(')
            {
                if(arr[i + 1] == '*')
                {
                    s.push('_');
                    ++i;
                    --j;
                }
                else
                    s.push(arr[i]);
            }

            else if(arr[i] == '}' || arr[i] == ']' || arr[i] == '>' || arr[i] == ')')
            {
                if(s.size() > 0 && s.top() == mm[arr[i]])
                    s.pop();
                else
                {
                    p = 0;
                    break;
                }
            }

            else if(arr[i] == '*' && arr[i + 1] == ')')
            {
                ++i;
                --j;
                if(s.size() > 0 && s.top() == '_')
                    s.pop();
                else
                {
                    p = 0;
                    break;
                }
            }
        }

        if(s.size() > 0)
        {
            p = 0;
        }

        if(p == 1)
            printf("YES\n");
        else
            printf("NO %d\n", i + j);
        while(!s.empty())
            s.pop();
    }
    return 0;
}
