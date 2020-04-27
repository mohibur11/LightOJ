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


using namespace std;

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

long long BigMod(long long int a, long long int b, int M) { /// a function to determine a^b(mod M)
    long long remainder, answer = 1;                            /// set two variables for remainder and answer
    remainder = a%M;                                         /// setting remainder as
    while(b!=0)                                                     ///  loop occurs until b is not equal to 0
    {
        if(b%2==1) answer = (answer*remainder)%M;                  /// checking if b is odd
                /// taking the present remainder in the answer if b is odd
        remainder = (remainder*remainder)%M;    /// making remainder double on each turn of the loop
        b/=2;                                  /// reducing b by dividing it by 2 in every turn,
    }
    return answer;
}
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.ss>b.ss) return 0;
    if(a.ss==b.ss) return a.ff>b.ff;
    return 1;
}

void SieveOfEratosthenes(int n, bool prime[],
						bool primesquare[], int a[])
{
	// Create a boolean array "prime[0..n]" and
	// initialize all entries it as true. A value
	// in prime[i] will finally be false if i is
	// Not a prime, else true.
	for (int i = 2; i <= n; i++)
		prime[i] = true;

	// Create a boolean array "primesquare[0..n*n+1]"
	// and initialize all entries it as false. A value
	// in squareprime[i] will finally be true if i is
	// square of prime, else false.
	for (int i = 0; i <= (n * n + 1); i++)
		primesquare[i] = false;

	// 1 is not a prime number
	prime[1] = false;

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then
		// it is a prime
		if (prime[p] == true) {
			// Update all multiples of p
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

	int j = 0;
	for (int p = 2; p <= n; p++) {
		if (prime[p]) {
			// Storing primes in an array
			a[j] = p;

			// Update value in primesquare[p*p],
			// if p is prime.
			primesquare[p * p] = true;
			j++;
		}
	}
}

// Function to count divisors
int countDivisors(int n)
{
	// If number is 1, then it will have only 1
	// as a factor. So, total factors will be 1.
	if (n == 1)
		return 1;

	bool prime[n + 1], primesquare[n * n + 1];

	int a[n]; // for storing primes upto n

	// Calling SieveOfEratosthenes to store prime
	// factors of n and to store square of prime
	// factors of n
	SieveOfEratosthenes(n, prime, primesquare, a);

	// ans will contain total number of distinct
	// divisors
	int ans = 1;

	// Loop for counting factors of n
	for (int i = 0;; i++) {
		// a[i] is not less than cube root n
		if (a[i] * a[i] * a[i] > n)
			break;

		// Calculating power of a[i] in n.
		int cnt = 1; // cnt is power of prime a[i] in n.
		while (n % a[i] == 0) // if a[i] is a factor of n
		{
			n = n / a[i];
			cnt = cnt + 1; // incrementing power
		}

		// Calculating number of divisors
		// If n = a^p * b^q then total divisors of n
		// are (p+1)*(q+1)
		ans = ans * cnt;
	}

	// if a[i] is greater than cube root of n

	// First case
	if (prime[n])
		ans = ans * 2;

	// Second case
	else if (primesquare[n])
		ans = ans * 3;

	// Third casse
	else if (n != 1)
		ans = ans * 4;

	return ans; // Total divisors
}

// Driver Program
vector<pair<int,int> > v;
int main()
{
    int n,t,caseno=1;
    for(int i=1;i<=1000;i++)
    {
        v.pb(mp(i,countDivisors(i)));
    }
    //rep(i,0,9) cout<< v[i].ff << " " << v[i].ss << endl;
    sort(v.begin(),v.end(),cmp);//rep(i,0,9) cout<< v[i].ff << " " << v[i].ss << endl;
    scin(t);
    while(t--)
    {
    scin(n);
    pf("Case %d: %d\n", caseno++,v[n-1]);

    }
	return 0;
}
