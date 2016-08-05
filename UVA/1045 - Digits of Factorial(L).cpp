#include <cstdio>
#include <math.h>

double d[1000005];

void digit(void)
{
    int i;
    d[0]=d[1]=0;
    for(i=2;i<1000001;++i)
    {
        d[i]=log10(i)+d[i-1];
    }
}

int main()
{
    int t,n,base,cnt;
    digit();
    scanf("%d",&t);
    for(cnt=1;cnt<=t;++cnt)
    {
        scanf("%d %d",&n,&base);
        printf("Case %d: %d\n",cnt,(int)(d[n]/log10(base))+1);
    }
    return 0;
}
