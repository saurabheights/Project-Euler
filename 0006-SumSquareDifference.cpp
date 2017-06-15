#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;

        long long temp = (n*(n+1))/2;
        long long squareOfSum = temp * temp;
        long long sumOfSquares = (temp*(2*n+1)) / 3;
        cout << (squareOfSum - sumOfSquares) << endl;
    }
    return 0;
}
