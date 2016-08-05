#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long int coin[]= {1,5,10,25,50}; //value of coins available
long long int dp[6][30010];

long long int call(long long int i, long long int amount)
{
    if(i>=5)     //All coins have been taken
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount]; //no need to calculate same state twice
    long long int ret1=0,ret2=0;
    if(amount-coin[i]>=0)
        ret1=call(i,amount-coin[i]); //try to take coin i
    ret2=call(i+1,amount); //dont take coin i
    return dp[i][amount]=ret1+ret2; //storing and returning.
}

int main()
{
    long long int make, ans;
    memset(dp,-1,sizeof(dp));
    while(scanf("%lld", &make) == 1)
    {
        ans = call(0, make);
        if(ans > 1)
            printf("There are %lld ways to produce %lld cents change.\n", ans, make);
        else
            printf("There is only 1 way to produce %lld cents change.\n", make);
    }
    return 0;
}

