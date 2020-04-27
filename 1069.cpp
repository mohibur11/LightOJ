#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,tm,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&x,&y);
        if(x<y)
        {
            tm=(y*4)+19;
        }
        else if(x>y)
        {
            tm=(((2*x)-y)*4) +19;
        }
        else
        {
            tm=(x*4) + 19;
        }
        printf("Case %d: %d\n", i,tm);
    }
    return 0;
}
