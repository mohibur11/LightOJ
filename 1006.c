#include<stdio.h>
int main()
{
    int  caseno = 0, cases,i;
    long long a[10005],n;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &n);
        for(i=6; i<=n; i++)
            a[i] = (a[i-1] + a[i-2] +a [i-3] +a[i-4] +a[i-5] +a[i-6]) % 10000007ll;
        printf("Case %d: %lld\n", ++caseno, a[n] % 10000007ll);
    }
    return 0;
}
