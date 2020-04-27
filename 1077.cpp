#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tst, caseno = 1;
    long long x1, x2, y1, y2, answer;
    cin >> tst;
    while(tst--)
    {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        answer = __gcd(abs(x1-x2), abs(y1-y2)) + 1ll;
        printf("Case %d: %lld\n", caseno++, answer);
    }
    return 0;
}
