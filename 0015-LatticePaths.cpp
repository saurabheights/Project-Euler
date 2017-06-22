#include <bits/stdc++.h>
using namespace std;

#define MODULO 1000000007L // 10^9 + 7 L

/**
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner. How many such routes are there through a 20×20 grid?
 */

/**
Solution:- Think of it as making N moves down and M moves down.
------------------------------- <- N+M spaces and each space should be filled with down or right
Solution (N+M)C(N)
 */

/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0) {
        if(b%2 == 1) {
            x= x * y;
            if(x>MOD) x%=MOD;
        }
        y = y * y;
        if( y > MOD)
            y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n, m;
        cin >> n >> m;
        cout << C(n+m, m, MODULO) << endl;
    }
    return 0;
}
