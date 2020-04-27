#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, q, i, tst, caseno = 0, sum;
    cin >> tst;
    while(tst--)
    {
        cin >> n >> p >> q;
        int dim[n];sum = 0;
        for(i = 0; i<n; i++)
            scanf("%d", &dim[i]);
        for(i = 0; i<n and i<p; i++)
        {

            sum+=dim[i];
            if(sum > q) break;
        }
        printf("Case %d: %d\n", ++caseno, i);
    }
    return 0;
}
