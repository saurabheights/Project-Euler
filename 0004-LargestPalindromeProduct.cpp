#include <bits/stdc++.h>
using namespace std;

const int MAX_RANGE = 1000000;

vector<bool> isDigitPalindrome (MAX_RANGE+1);
void computeSixDigitPalindromeNumbers() {
    for (int i = 101; i <= 999; ++i)
    {
        // Reverse abc;
        // i = 100a +10b + c
        // o = 100c + 10b +a
        int a = i / 100;
        if(a != 0) { // Cant be a 6 digit number if ends with 0
            int b = (i/10) % 10;
            int c = i % 10;
            int o = (100 * c + 10*b + a);
            int palin = i*1000+o;
            isDigitPalindrome[palin] = true;
        }
    }
}

vector<bool> isPalindromeProductOfThreeDigitNumbers (MAX_RANGE+1);
void computeSixDigitPalindromeNumbersFormedByProductOfThreeDigitNumbers() {
    for (int i = 101; i <= 999; ++i)
    {
        for (int j = 101, t = i*j; j <= 999; ++j, t+=i)
        {
            if(isDigitPalindrome[t]) {
                isPalindromeProductOfThreeDigitNumbers[t] = true;
            }
        }
    }
}

int main() {
    computeSixDigitPalindromeNumbers();
    computeSixDigitPalindromeNumbersFormedByProductOfThreeDigitNumbers();
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        n--
        // Using Binary Search in a vector storing only palindrome which are product of three digit numbers will be even faster.
        while(!isPalindromeProductOfThreeDigitNumbers[n]) n--;
        cout << n << endl;
    }
    return 0;
}
