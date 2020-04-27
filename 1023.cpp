#include<bits/stdc++.h>
using namespace std;
int main()
{
    string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int tst, caseno=1,i;
    cin >> tst;
    while(tst--)
    {
        int cnt=1,k,n;
    cin>>n>>k;
    char a[100];
    for( i=0;i<n;i++)
        a[i]=b[i];
    a[i]='\0';
    printf("Case %d:\n",caseno++);
    do
    {
        cout << a<<endl;
        cnt++;
    }
    while(next_permutation(a,a+n)&&cnt<=k);}
    return 0;
}

