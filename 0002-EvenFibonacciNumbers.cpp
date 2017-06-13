#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long long a = 3, b = 5, c = 8; // a is not needed though
        long long solution = 2;
        while(c < n) {
            solution +=c;
            long long t = c;
            c += (c+b)<<1; // c = 3*c+2*b;
            b += t<<1;  // b = 2*t+b;
        }
        cout << solution << endl;
    }
    return 0;
}
