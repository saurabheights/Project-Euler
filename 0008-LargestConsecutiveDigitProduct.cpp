#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        int maxProduct = 0;
        for (int i = 0; i < n - k + 1; ++i)
        {
            int product = num[i] - '0';
            for (int j = i+1; j < i+k; ++j)
            {
                product*= (num[j] - '0');
                if(product == 0)
                    break;
            }
            if(product > maxProduct) {
                maxProduct = product;
            }
        }
        cout << maxProduct << endl;
    }
    return 0;
}
