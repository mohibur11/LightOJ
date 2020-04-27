#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int t,i,rem;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        int cnt=0;
        while(n!=0)
        {
            rem=n%2ll;
            if(rem==1)
                cnt++;
            n/=2ll;

        }
        if(cnt%2==0)
        printf("Case %d: even\n", i);
        else
            printf("Case %d: odd\n",i);
    }
    return 0;
}
