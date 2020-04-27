#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m,i,j,cnt;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        cnt=1;
        long long sum=0,n;
        scanf("%lld %d",&n,&m);
        sum=(m*n)/2;
        printf("Case %d: %lld\n",i,sum);
    }
    return 0;
}
