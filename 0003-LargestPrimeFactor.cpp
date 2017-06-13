#include <bits/stdc++.h>
using namespace std;

const int MAX_RANGE = 1000000;
vector<bool> isPrimeArr (MAX_RANGE+1);

void initPrimeArray() {
    fill(begin(isPrimeArr), end(isPrimeArr), true);
    isPrimeArr[0] = isPrimeArr[1] = false;
    int sqrtRange = sqrt(MAX_RANGE) + 1;
    for (int i = 2; i <= sqrtRange; ++i)
    {
        if(isPrimeArr[i]) {
            for (int j = i*i; j <= MAX_RANGE; j+=i)
            {
                isPrimeArr[j] = false;
            }
        }
    }
}

bool isPrime(long long n) {
    if(n <= MAX_RANGE) {
        return isPrimeArr[n];
    } else {
        cout << n << " ";
        for (long long i = 2; i <= sqrt(n) + 1; ++i) {
            if( n % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    initPrimeArray();
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long prevN = n;
        long long maxPrime = -1;
        long long sqrtN = sqrt(n) + 1;
        // largest prime can be greater than sqrtN, but it will be equal to final value of n 
        // after dividing from small prime numbers(i < n && n%i == 0 && isPrimeArr[i]).
        for (int i = 2; i <= sqrtN && i < n; ++i)
        {
            if(isPrimeArr[i] && (n % i == 0)) {
                maxPrime = i;
                n/=i;
                while(n % i == 0) {
                    n /= i;
                }
            }
        }

        if(maxPrime < n) {
            maxPrime = n;
        }
        cout << maxPrime << endl;
    }
    return 0;
}