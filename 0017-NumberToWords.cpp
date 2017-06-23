#include <bits/stdc++.h>
using namespace std;

string speakNumHuman[21] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
                            "Nineteen", "Twenty"};
string speakTensNumHuman[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string speakHuman(long long n, long long thousandIndex) {
    string s;
    if(n >= 1000) {
        s = speakHuman(n / 1000, thousandIndex+1);
    }

    n = n % 1000;
    if(n == 0)
        return s;
    // Convert n to human speech
    long long hundred = n / 100; 
    n %= 100;
    long long tenth = n / 10;
    long long ones = n % 10;

    if(hundred > 0) {
        if(s.length() > 0)
            s += " " + speakNumHuman[hundred] + " Hundred";
        else
            s += speakNumHuman[hundred] + " Hundred";
    }

    if( n > 9 && n <= 20) {
        if(s.length() > 0)
            s += " " + speakNumHuman[tenth*10 + ones];
        else
            s += speakNumHuman[tenth*10 + ones];
    } else if(n > 0) {
        if(tenth > 0) {
            if(s.length() > 0)
                s += " " + speakTensNumHuman[tenth];
            else
                s += speakTensNumHuman[tenth];
        }
        
        if(ones > 0) {
            if(s.length() > 0) {
                s += " " + speakNumHuman[ones];
            } else if (ones){
                s += speakNumHuman[ones];
            }
        }
    }

    // Append thousand Index
    switch(thousandIndex) {
        case 1:
        s += " Thousand";
        break;
        case 2:
        s += " Million";
        break;
        case 3:
        s += " Billion";
        break;
        case 4:
        s += " Trillion";
        default:
        break;
    }
    return s;
}

int main(){
    long long t;
    cin >> t;
    for(long long a0 = 0; a0 < t; a0++) {
        long long n;
        cin >> n;
        if(n == 0)
            cout << "Zero" << endl;
        cout << "\"" << speakHuman(n, 0)<< "\"" << endl;
    }
    return 0;
}
