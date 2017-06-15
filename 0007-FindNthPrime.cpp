#include <bits/stdc++.h>
using namespace std;

const int MAX_RANGE = 1000000;
vector<bool> isPrimeArr (MAX_RANGE);

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

int main(){
    initPrimeArray();
    int primeValues[10000];
    int primeCount = 0;
    for (int i = 0; i < MAX_RANGE; ++i)
    {
        if(isPrimeArr[i]) {
            primeValues[primeCount++] = i;
        }
        if(primeCount == 10000) {
            break;
        }
    }
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << primeValues[n-1] << endl;
    }
    return 0;
}
