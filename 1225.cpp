#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j;
    char a[20],b[20];
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        int len,cnt=0;
        scanf("%s",a);
        len=strlen(a);
        for(j=0;j<len;j++)
        {
            if(a[j]==a[len-j-1])
                cnt++;
        }
        if(cnt==len)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);

    }
    return 0;
}

