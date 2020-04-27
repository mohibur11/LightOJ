#include<bits/stdc++.h>
using namespace std;
int pw(int n,int x)
{
    if(x==0)
        return 1;
    else
    return n*pw(n,x-1);
}
int main()
{
    int t,a1,b1,c1,d1,a2,b2,c2,d2,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int bin1=0,bin2=0,bin3=0,bin4=0;
        scanf("%d.%d.%d.%d", &a1,&b1,&c1,&d1);
        scanf("%d.%d.%d.%d", &a2,&b2,&c2,&d2);
        for(j=0;j<8;j++)
        {
            bin1+=(a2%10)*pw(2,j);
            bin2+=(b2%10)*pw(2,j);
            bin3+=(c2%10)*pw(2,j);
            bin4+=(d2%10)*pw(2,j);
            a2/=10;b2/=10;c2/=10;d2/=10;
        }
        if(bin1==a1&&bin2==b1&&bin3==c1&&bin4==d1)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }
    return 0;
}
