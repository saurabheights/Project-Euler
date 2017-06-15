#include <bits/stdc++.h>
using namespace std;

const int MAX_RANGE = 1000000;
vector<bool> isPrimeArr (MAX_RANGE+1);
vector<long long> sumOfPrimesSmallerThanN (MAX_RANGE+1);
void initPrimeArray() {
    fill(begin(isPrimeArr), end(isPrimeArr), true);
    isPrimeArr[0] = isPrimeArr[1] = false;
    sumOfPrimesSmallerThanN[1] = 0;
    int sqrtRange = sqrt(MAX_RANGE) + 1;
    for (int i = 2; i <= sqrtRange; ++i)
    {
        if(isPrimeArr[i]) {
            sumOfPrimesSmallerThanN[i] = sumOfPrimesSmallerThanN[i-1] + i;
            for (int j = i*i; j <= MAX_RANGE; j+=i)
            {
                isPrimeArr[j] = false;
            }
        } else
            sumOfPrimesSmallerThanN[i] = sumOfPrimesSmallerThanN[i-1];
    }
    for (int i = 2; i <= MAX_RANGE; ++i)
    {
        if(isPrimeArr[i]) {
            sumOfPrimesSmallerThanN[i] = sumOfPrimesSmallerThanN[i-1] + i;
        } else
            sumOfPrimesSmallerThanN[i] = sumOfPrimesSmallerThanN[i-1];
    }
}

int main(){
    initPrimeArray();
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << sumOfPrimesSmallerThanN[n] << endl;
    }
    return 0;
}