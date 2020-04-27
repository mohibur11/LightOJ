#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x1,y1,x2,y2,x,y,i,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n);
        printf("Case %d:\n",i);
        for(j=1;j<=n;j++)
        {
            scanf("%d %d",&x,&y);
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
