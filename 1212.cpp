#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,n,m,itm,j,cnt;
    char a[20];
    deque  <int > Q;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",i);
        cnt=0;
        for(j=1; j<=m; j++)
        {
            scanf("%s",a);
            if(a[1]=='u')
            {
                scanf("%d",&itm);
                if(cnt==n)
                    printf("The queue is full\n");
                else if(a[4]=='L')
                {
                    printf("Pushed in left: %d\n", itm);
                    Q.push_front(itm);
                    cnt++;
                }
                else if(a[4]=='R')
                {
                    printf("Pushed in right: %d\n", itm);
                    Q.push_back(itm);
                    cnt++;
                }
            }
            else if(a[1]=='o')
            {
                if(cnt==0)
                    printf("The queue is empty\n");
                else if(a[3]=='L')
                {
                    printf("Popped from left: %d\n", Q.front());
                    Q.pop_front();
                    cnt--;
                }
                else if(a[3]=='R')
                {
                    printf("Popped from right: %d\n", Q.back());
                    Q.pop_back();
                    cnt--;
                }
            }
        }
        Q.clear();
    }
    return 0;
}
