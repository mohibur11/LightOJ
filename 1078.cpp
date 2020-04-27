#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int tst, i, n, d, sum, caseno = 1;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d %d", &n, &d);
        sum = d;
        for(i=1; ;i++)
        {
            if(sum%n==0) break;
            sum=sum%n;
            sum = 10 *sum +  d;

        }
        printf("Case %d: %d\n", caseno++,i);
    }
    return 0;
}
