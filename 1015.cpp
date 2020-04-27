#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,i,j;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int sum=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a);
            if(a>0)
                sum+=a;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
