/** Bismillahir Rahmanir Rahim **/
/** Learn from codeforces flash_7 blog **/
#include<bits/stdc++.h>

#define ll              long long int
#define NL              pf("\n")

using namespace std;

vector<ll> num;
ll dp[30][30][4][4], a, b, d, k;
ll call(ll pos, ll cnt, bool f,bool zero_f) /// this function give how many numbers have d digit exactly k times in range a to b
{
    if(cnt > k ) return 0ll;

    if(num.size() == pos)
    {
        if(cnt == k) return 1ll;
        return 0ll;
    }
    if(dp[pos][cnt][f][zero_f]!=-1)return dp[pos][cnt][f][zero_f];

    ll LMT;
    if(f == 0) LMT = num[pos];
    else LMT = 9ll;
    ll res = 0ll;
    for(int dgt = 0; dgt <= LMT; dgt++)
    {
        ll ncnt = cnt;
        ll nf = f;
        ll nzero = zero_f;

        if(zero_f == 0 && dgt != 0) nzero = 1;  /// zero_f for not count of leading zeros

        if(f == 0 && dgt < LMT) nf = 1;
        if(dgt == d && (d !=0  || (d == 0 && zero_f)))ncnt++;
        if(ncnt<=k) res+=call(pos+1, ncnt, nf,nzero);
    }
    return dp[pos][cnt][f][zero_f] = res;
}
ll solve(ll n)
{
    if(n<0)return 0;
    if(n<=9) return 1;
    num.clear();
    while(n)    /// insert each digit of number into a vector
    {
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(),num.end());
    ll res = 0ll;d = 0ll;
    for(int length = 1;length <num.size();length++ ) /// call for find how many number have exactly k digit, here k is changing
    {
        memset(dp, -1, sizeof(dp));
        k = length;
        res += (call(0ll,0ll,0,0) * k);
    }
    return res +1;
}
int main()
{

    int t, T;
    ll ans;
    scanf("%d", &T);
    for(t = 1;t<=T;t++)
    {
        scanf("%lld %lld", &a, &b);
        ans = solve(b) - solve(a-1);
        printf("Case %d: %lld\n",t, ans);
    }
    return 0;
}
