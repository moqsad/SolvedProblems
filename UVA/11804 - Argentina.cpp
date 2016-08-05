#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct data
{
    int attack, defense;
    string s;
};

vector <data> info;

vector <string> arr;

bool comp(data p, data q)
{
//    if(p.attack > q.attack)
//        return 1;
//    else if(p.attack < q.attack)
//        return 0;
    if(p.attack != q.attack)
        return p.attack > q.attack;
    else
    {
//        if(p.defense < q.defense)
//            return 1;
//        else if(p.defense > q.defense)
//            return 0;
        if(p.defense != q.defense)
            return p.defense < q.defense;
        else
            return p.s < q.s;
    }
}

int main()
{
    int t, cnt, i, j;
    data x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        for(i = 0; i < 10; ++i)
        {
            cin >> x.s;
            scanf("%d %d", &x.attack, &x.defense);
            info.push_back(x);
        }

        sort(info.begin(), info.end(), comp);

//        for(i = 0; i < 9; ++i)
//        {
//            for(j = i + 1; j < 10; ++j)
//            {
//                if(info[i].attack < info[j].attack)
//                {
//                    x = info[i];
//                    info[i] = info[j];
//                    info[j] = x;
//                }
//
//                else if(info[i].attack == info[j].attack)
//                {
//                    if(info[i].defense > info[j].defense)
//                    {
//                        x = info[i];
//                        info[i] = info[j];
//                        info[j] = x;
//                    }
//
//                    else if(info[i].defense == info[j].defense)
//                    {
//                        if(info[i].s > info[j].s)
//                        {
//                            x = info[i];
//                            info[i] = info[j];
//                            info[j] = x;
//                        }
//                    }
//                }
//            }
////            cout << info[i].s << "\n";
//        }

        printf("Case %d:\n", cnt);

        for(i = 0; i < 5; ++i)
            arr.push_back(info[i].s);

        sort(arr.begin(), arr.end());
        cout << "(" << arr[0];
        for(i = 1; i < 5; ++i)
            cout << ", " << arr[i];
        printf(")\n");

        arr.clear();

        for(i = 5; i < 10; ++i)
            arr.push_back(info[i].s);

        sort(arr.begin(), arr.end());
        cout << "(" << arr[0];
        for(i = 1; i < 5; ++i)
            cout << ", " << arr[i];
        printf(")\n");
        info.clear();
        arr.clear();
    }
    return 0;
}
