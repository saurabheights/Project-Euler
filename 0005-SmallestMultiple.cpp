#include <bits/stdc++.h>
using namespace std;

const int MAX_RANGE = 50;

vector<bool> isPrimeArr (MAX_RANGE);
vector<vector<pair<int, int> > > listOfPrimeFactorsAndTheirPower(MAX_RANGE+1);

int primeVal[MAX_RANGE+1];
// Computes prime factor for each number from 1 to MAX_VALUE. MAX_VALUE <= MAX_RANGE.
void initPrimaFactorizationOverRange(int MAX_VALUE) {
    fill(begin(isPrimeArr), end(isPrimeArr), true);
    for (int i = 0; i <= MAX_VALUE; ++i)
    {
        primeVal[i] = i;
    }
    isPrimeArr[0] = isPrimeArr[1] = false;
    for (int i = 2; i <= MAX_VALUE; ++i)
    {
        if(isPrimeArr[i]) {
            for (int j = i; j <= MAX_VALUE; j+=i) {
                isPrimeArr[j] = false;
                primeVal[j] /= i;
                pair<int, int> p(i, 1);
                while(primeVal[j] % i == 0) {
                    primeVal[j] /= i;
                    std::get<1>(p)++;
                }
                listOfPrimeFactorsAndTheirPower[j].push_back(p);
            }
        }
    }
    // for (int i = 2; i <= MAX_VALUE; ++i)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < listOfPrimeFactorsAndTheirPower[i].size(); ++j)
    //     {
    //         cout << "(" << get<0>(listOfPrimeFactorsAndTheirPower[i][j]) << "," <<  get<1>(listOfPrimeFactorsAndTheirPower[i][j])  << ") ";
    //     }
    //     cout << endl;
    // }
}

/**
 * Find LCM of numbers from 1 to n.
 */
long long computeLCM(int n) {
    if(n == 1) return 1;
    map<int, int> factorAndTheirPowers;
    for (int i = 2; i <= n; ++i)
    {
        vector<pair<int, int> > factorsPowerPairssOfI = listOfPrimeFactorsAndTheirPower[i];
        for (std::vector<pair<int, int> >::iterator it = factorsPowerPairssOfI.begin(); it != factorsPowerPairssOfI.end(); ++it)
        {
            pair<int, int> factorPowerPair = *it;
            int factor = get<0>(factorPowerPair);
            int power = get<1>(factorPowerPair);
            if(factorAndTheirPowers[factor] < power)
                factorAndTheirPowers[factor] = power;
        }
    }
    long long LCM = 1L;
    for(map<int, int>::iterator it = factorAndTheirPowers.begin();
        it != factorAndTheirPowers.end();
        it++) {
        int factor = it->first;
        int power = it->second;
        while(power > 0) {
            LCM *= factor;
            power--;
        }
    }
    return LCM;
}

int main() {
    initPrimaFactorizationOverRange(40);
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << computeLCM(n) << endl;
    }
    return 0;
}
