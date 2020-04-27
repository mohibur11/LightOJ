#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tst, a, b, i;
    scanf("%d", &tst);
    for(i=1; i<=tst; i++)
    {
        int cnt=0;
        scanf("%d %d", &a, &b);
        while((a-1)%3 != 0)
        {
            a++;
            cnt++;
        }
        while((b-1)%3 != 0)
        {
            b--;
            cnt++;
        }
        cnt+= ((b-a)/3)*2;
        printf("Case %d: %d\n", i, cnt);
    }
    return 0;
}
