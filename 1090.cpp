#include<bits/stdc++.h>

#define ll              long long int
#define ull             unsigned long long int
#define pii             pair < int, int>
#define pll             pair < ll, ll>
#define sc              scanf
#define scin(x)         sc("%d",&(x))
#define scln(x)         sc("%lld",&(x))
#define pf              printf
#define NL              pf("\n")
#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define mp              make_pair
#define db              double
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define vi              vector< int >
#define vl              vector< ll >
#define vii             vector<vector< int > >
#define vll             vector<vector< ll > >
#define DBG             pf("HI\n")
#define MOD             1000000007
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RUN_CASE(t,T)   for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)         printf("Case %d: ",t)
#define CASEL(t)        printf("Case %d:\n",t)
#define intlimit        2147483648
#define longlimit       9223372036854775808
#define infinity        (1<<28)
#define gcd(a, b)       __gcd(a,b)
#define lcm(a, b)       ((a)*(b)/gcd(a,b))
#define mx              1234567899
#define PI              2*acos(0.0)
#define rep(i,a,b)      for(ll i=a; i<=b; i++)
#define rev(i,a,b)      for(ll i=a; i>=b; i--)
#define file            freopen("E:\\file.txt", "r", stdin);ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x)            x.begin(),x.end()
using namespace std;

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
int szz = 1000001;
int cnt[1000001][4];
void count2_5()
{
    int tmp;
    for(int i=1;i<=szz;i++)
    {
        tmp = i;
        while(tmp)
        {
            cnt[i][0]+=tmp/2;
            tmp/=2;
        }
        tmp = i;
        while(tmp)
        {
            cnt[i][1]+=tmp/5;
            tmp/=5;
        }
    }
}
ll two,five;
void count_2_5_in_pq(int p,int q)
{
        while(p%2==0)
        {
            two++;
            p/=2;
        }
        while(p%5==0)
        {
            five++;
            p/=5;
        }
        five = five*q;
        two = (two*q);


}
int main()
{
    int t,T, tmp;
    count2_5();
    scin(T);
    ll n,p,r,q, Total_two,Total_five;
    RUN_CASE(t,T)
    {

        sc("%lld %lld %lld %lld", &n,&r,&p,&q);
        two = 0;five = 0;
        count_2_5_in_pq(p,q);

        Total_two = (cnt[n][0]+two) - (cnt[n-r][0]+cnt[r][0]);
        Total_five = (cnt[n][1]+five) - (cnt[n-r][1]+cnt[r][1]);

        CASE(t);
        pf("%d\n", min(Total_five,Total_two));

    }
    return 0;
}

