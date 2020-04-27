#include<bits/stdc++.h>
using namespace std;
#define SIZE 100000007
int SP[SIZE];
int LCM[SIZE];
bool seive[SIZE];
void find_smallest_prime_factor(int n)
{
    LCM[1] = 1;
    for(int i=2; i<=n; i++){

        if(SP[i]==0){           ///checks if it is not counted before
            seive[i] = 1;
            SP[i] = i;
            LCM[i] = LCM[i-1] * i;
            for(int j=i; j<=n; j=j*i; ){
                if(SP[j]==0)
                    SP[j] = i;
            }
        }
        else
        {
            LCM[i] = LCM[i-1] * SP[i];
        }
    }
}

int main()
{
    find_smallest_prime_factor(SIZE);
    int n;
    while(cin >> n)
    {
        cout << SP[n] << " " << LCM[n] << "\n ";
    }
    return 0;
}
