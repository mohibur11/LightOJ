#include<stdio.h>
int main()
{
    int T,a,b,c,d=0;
    printf("Greetings from LightOJ");
    scanf("%d", &T);
    for(c=1; c<=T; c++)
    {
        scanf("%d%d", &a,&b);
        d=a+b;
        printf("Case %d: %d\n", c,d);
    }
    return 0;
}
