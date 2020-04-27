#include <bits/stdc++.h>

using namespace std;
int main()
{
    int tst, caseno = 1;
    double ab, ac, bc, onu, ad;
    cin >> tst;
    while(tst--)
    {
        cin >> ab >> ac >> bc >> onu;
        onu = onu / (onu + 1);
        ad = sqrt(onu) * ab;
        printf("Case %d: %lf\n", caseno++, ad);
    }
    return 0;
}
