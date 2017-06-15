#include <bits/stdc++.h>
using namespace std;

// The triangle inequality property
// The length of a side should be less than the sum and greater than the difference of the lengths of the other two sides.
// a < b+c, b < a+c, c < a+c
int main() {
    int squareArr[1501] = {0};
    for (int i = 1; i < 1501; ++i)
    {
        squareArr[i] = i*i;
    }

    int N = 3000;
    int maxPythaProduct[3001] = {0};
    for (int N = 0; N < 3001; ++N)
    {
        maxPythaProduct[N] = -1;
    }

    int midLength = (N+2)>>1;
    for (int a = 1; a <= midLength; ++a)
    {
        for (int b = a; b <= midLength && (a+b) < N; ++b)
        {
            for (int c = b; c <= min(min(a+b, midLength), N-(a+b)); ++c)
            {
                int n = a+b+c;
                int min1 = min(min(a,b), c);
                int max1 = max(max(a,b), c);
                int middle = n - max1 - min1;
                if(squareArr[min1] + squareArr[middle] == squareArr[max1]) {
                    int pytha = min1 * middle * max1;
                    if(pytha > maxPythaProduct[n]) {
                        maxPythaProduct[n] = pytha;
                    }
                }
            }
        }
    }

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << maxPythaProduct[n] << endl;
    }
    return 0;
}
