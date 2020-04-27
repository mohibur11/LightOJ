#include<bits/stdc++.h>
using namespace std;
int main()
{
    double r,R,deg,rad;
    int n,t,i;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf%d",&R,&n);
        deg=(360.0/(2.0*n));
        rad=(M_PI*deg)/180;
        r=(R*sin(rad))/(1+sin(rad));
        printf("Case %d: %lf\n",i,r);
    }
    return 0;
}

