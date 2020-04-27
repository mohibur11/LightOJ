#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tst, caseno = 0, Ax, Bx, Ay, By, Cx, Cy, Dx, Dy, area, a, b, c, d;
    cin >> tst;
    while(tst--)
    {
        scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
        Dx = Cx - ( Bx - Ax );
        Dy = Cy - ( By - Ay );
        a = ( Bx - Ax );
        b = ( By - Ay );
        c = ( Cx - Ax );
        d = ( Cy - Ay );
        area = ( a * d ) - ( c * b );
        printf("Case %d: %d %d %d\n", ++caseno, Dx, Dy, abs(area));
    }
    return 0;
}
