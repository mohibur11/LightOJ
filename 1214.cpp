#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char a[205];
    long long int b, tst, i, rem, x, caseno = 1ll;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%s %lld", a, &b);

        int len = strlen(a);
        if(a[0]=='-')  {rem = a[1]-48ll;x = 2ll;}
        else           {rem = a[0]-48ll;x = 1ll;}


        for(i=x;i<len;i++)
        {
            rem = rem % b;
            rem = rem * 10ll + a[i]-48ll;
        }
        rem %= b;


        if(rem == 0ll)
            printf("Case %d: divisible\n", caseno++);
        else
            printf("Case %d: not divisible\n", caseno++);
    }
    return 0;
}
