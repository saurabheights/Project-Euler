#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        n--;
        
        // count each multiple of 3 - 3, 6, 9
        long long threes = n/3;
        // count sum of each multiple of 3 - 3 + 6 + 9 ... = 3 * (1+2+3...)
        long long threesSum = 3*(threes * (threes+1))/2;

        // Repeat for 5 and 15.
        long long fives = n/5;
        long long fivesSum = 5*(fives * (fives+1))/2;
        long long fifteens = n/15;
        long long fifteensSum = 15*(fifteens * (fifteens+1))/2;
        cout << threesSum + fivesSum - fifteensSum << endl;
    }
    return 0;
}
