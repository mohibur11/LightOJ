#include <bits/stdc++.h>


using namespace std;

int main()
{
    int tst, caseno = 0;
    double r1, r2, h, p, R2,v;
    cin >> tst;
    while(tst--)
    {
        cin >> r1 >> r2 >> h >> p;
        R2 = r2 + (r1 - r2)* (p / h);
        v = ((M_PI*p)/3)*(r2*r2 + r2*R2 + R2*R2);
        printf("Case %d: %.9lf\n", ++caseno, v);
    }
    return 0;
}
