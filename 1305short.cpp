#include<iostream>
#include<cstdio>
#include <stdlib.h>
using namespace std;
int main()
{
    int tst, caseno = 0, Ax, Bx, Ay, By, Cx, Cy, Dx, Dy, area;
    scanf("%d" , &tst);
    while(tst--)
    {
        scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
        Dx = Cx - ( Bx - Ax );
        Dy = Cy - ( By - Ay );
        area = ( ( Bx - Ax ) * ( Cy - Ay ) ) - ( ( Cx - Ax ) * ( By - Ay ) );
        printf("Case %d: %d %d %d\n", ++caseno, Dx, Dy, abs(area));
    }
    return 0;
}

