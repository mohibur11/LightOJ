#include<bits/stdc++.h>
using namespace std;
vector <int> l,r;
int main()
{
   int t,T;
   int i,j,k;
   int n,q;
   scanf("%d",&T);
   for(t=1;t<=T;t++){
   scanf("%d %d",&n,&q);
   for(i=0;i<n;i++){
       scanf("%d %d",&j,&k);
       l.push_back(j);
       r.push_back(k);
   }
   sort(l.begin(),l.end());
   sort(r.begin(),r.end());
   printf("Case %d:\n",t);
   for(i=0;i<q;i++){
      scanf("%d",&j);
      k=(upper_bound(l.begin(),l.end(),j)-l.begin())-(lower_bound(r.begin(),r.end(),j)-r.begin());
      printf("%d\n",k);
   }
   l.clear();
   r.clear();
   }
}
