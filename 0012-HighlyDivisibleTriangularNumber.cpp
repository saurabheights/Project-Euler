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
}

long long minimumNumberWithNFactors[1001] = {0};
void findMinimumNumberWithNFactors(int maxRange) {
    minimumNumberWithNFactors[0] = 1; // Exception, but not needed
    long long i = 1;
    int totalComputed = 0;
    int minIndex = 1;
    for (int t = 2; ; t++)
    {
        i += t;

        // i is divisible by t and t+1/2 or t/2 and t+1. Find these factors.
        int firstFactor, secondFactor;
        if(t % 2 == 0) {
            firstFactor = t>>1;
            secondFactor = t+1;
        } else {
            firstFactor = (t+1) >> 1;
            secondFactor = t;
        }

        // Combine factors of the two factors of i
        vector<pair<int, int> > factorsOfFirstFactor = listOfPrimeFactorsAndTheirPower[firstFactor];
        vector<pair<int, int> > factorsOfSecondFactor = listOfPrimeFactorsAndTheirPower[secondFactor];
        
        map<int, int> allFactors;
        for (std::vector<pair<int, int> >::iterator it = factorsOfFirstFactor.begin(); it != factorsOfFirstFactor.end(); ++it)
        {
            pair<int, int> factorPowerPair = *it;
            int factor = get<0>(factorPowerPair);
            int power = get<1>(factorPowerPair);
            allFactors[factor] = power;
        }
        for (std::vector<pair<int, int> >::iterator it = factorsOfSecondFactor.begin(); it != factorsOfSecondFactor.end(); ++it)
        {
            pair<int, int> factorPowerPair = *it;
            int factor = get<0>(factorPowerPair);
            int power = get<1>(factorPowerPair);
            allFactors[factor] += power;
        }

        // Count total factors of i
        long totalFactors = 1;
        for (map<int, int>::iterator it = allFactors.begin(); it != allFactors.end(); ++it)
        {
            int factor = it->first;
            int power = it->second;
            totalFactors *= (power+1);
        }

        // Cache values
        while(minIndex < totalFactors)
        {
            if(minimumNumberWithNFactors[minIndex] == 0) {
                totalComputed++;
            }
            minimumNumberWithNFactors[minIndex] = i;
            if(totalComputed == maxRange) {
                return;
            }
            minIndex++;
        }
    }
}

int main(){
    initPrimaFactorizationOverRange(MAX_RANGE);
    findMinimumNumberWithNFactors(1000);
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << minimumNumberWithNFactors[n] << endl;
    }
    return 0;
}
