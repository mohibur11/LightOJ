#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    double r,aoc,aos,result;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        aos=(r*2*r*2);
        aoc=M_PI*r*r;
        result = aos-aoc;
        printf("Case %d: %.2lf\n",i,result);
    }
    return 0;
}
