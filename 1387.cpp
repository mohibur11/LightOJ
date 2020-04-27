#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    char a[10];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int n;
        printf("Case %d:\n",i);
        scanf("%d",&n);
        int sum=0,dnt;
        while(n--)
        {
            scanf("%s",a);
            if(a[0]=='d')
            {
                scanf("%d",&dnt);
                sum+=dnt;
            }
            else if(a[0]=='r')
                printf("%d\n",sum);
        }
    }
    return 0;
}
