#include <bits/stdc++.h>
using namespace std;

/**
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
              13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 */

/**
Solution:- We will reverse the Collatz conjecture, and will generate all numbers from 1.
So, how does this work:-
For each k, generate next numbers(1 or 2) as follows
k → 2k (if k%6 != 4)
k → 2k, (k-1)/3 (if k%6 == 4) - Why? k should be odd as well as k-1 should be divisible by 3

Note, there is exception, 1->2->4->1. Write a code which does not gets stuck in cycle. Basically, if a node(number) has been marked as solved, do not solve it again.
 */

const int MAX_RANGE = 5000000;

class CollatzSequence {
public:
    long long number; // The start number in collatz conjecture.
    int chainLength; // Since cycles are very short, no need to worry.
    CollatzSequence(int number, int chainLength): number(number), chainLength(chainLength) {}
    CollatzSequence(int number): number(number), chainLength(0) {}
    CollatzSequence(): number(0), chainLength(0) {}

    /**
     * This method can be used to compute chain length for a number which might have been missed in computeCollatzSequences.
     */
    void computeChainLength() {
        long long temp = number;
        chainLength = 1;
        while(number != 1) {
            if((number & 0x1) == 0x0) {
                number>>=1;
            } else {
                number *= 3;
                number++;
            }
            chainLength++;
        }
    }
};

vector<CollatzSequence> allCollatzSequences(MAX_RANGE + 1); // Add one for one-index

void computeCollatzSequences() {
    long long MAX_BRUTE_ELEMENT = MAX_RANGE * 5L;
    // cout << MAX_BRUTE_ELEMENT << endl;
    queue<CollatzSequence> myqueue;
    int count = 1; // Sequences counted from 1 to MAX_RANGE
    CollatzSequence firstCollatzSequence(1,1);
    allCollatzSequences[1] = firstCollatzSequence;
    myqueue.push(firstCollatzSequence);
    while(!myqueue.empty()) {
        if(count == MAX_RANGE) {
            cout << "Found all" << endl; // Will not happen. and finds 4587966 out of 5000000 elements.
            break;
        }
        // Get first collatz sequence
        CollatzSequence collatzSequence = myqueue.front();
        myqueue.pop();

        // Check if this number is way over the MAX_RANGE and should not be further studied. 
        if(collatzSequence.number > MAX_BRUTE_ELEMENT) {
            continue;
        }

        // Find next element in this sequence
        if(collatzSequence.number % 6 == 4) {
            long long nextSequenceElement = (collatzSequence.number - 1) / 3;
            if(nextSequenceElement <= MAX_RANGE && allCollatzSequences[nextSequenceElement].chainLength != 0) {
                // Found a chain, ignore
                // cout << "1 - Found a chain, ignoring " << collatzSequence.number << " transition to " << nextSequenceElement << endl;
            } else {
                CollatzSequence nextCollatzSequence(nextSequenceElement, collatzSequence.chainLength + 1);
                if(nextSequenceElement <= MAX_RANGE) {
                    allCollatzSequences[nextSequenceElement] = nextCollatzSequence;
                    count++;
                }
                myqueue.push(nextCollatzSequence);
            }
        }
        long long nextSequenceElement = collatzSequence.number << 1;
        if(nextSequenceElement <= MAX_RANGE && allCollatzSequences[nextSequenceElement].chainLength != 0) {
            // Found a chain, ignore
            // cout << "2 - Found a chain, ignoring " << collatzSequence.number << " transition to " << nextSequenceElement << endl;
        } else {
            CollatzSequence nextCollatzSequence(nextSequenceElement, collatzSequence.chainLength + 1);
            if(nextSequenceElement <= MAX_RANGE) {
                allCollatzSequences[nextSequenceElement] = nextCollatzSequence;
                count++;
            }
            myqueue.push(nextCollatzSequence);
        }
    }
    // cout << "Found elements  = " << count << endl;
    for (int i = MAX_RANGE; i >= 1; i--)
    {
        if(count == MAX_RANGE)
            break;
        if(allCollatzSequences[i].chainLength == 0) {
            allCollatzSequences[i].number = i;
            allCollatzSequences[i].computeChainLength();
            count++;
        }
    }
}

vector<int> numberWithLargestChain(MAX_RANGE + 1);
int main(){
    computeCollatzSequences();
    numberWithLargestChain[0] = 0;
    int maxCycleLength = 0, maxCycleLengthIndex = 0;
    for (int i = 1; i <= MAX_RANGE; ++i)
    {
        if(maxCycleLength <= allCollatzSequences[i].chainLength) {
            maxCycleLength = allCollatzSequences[i].chainLength;
            maxCycleLengthIndex = i;
        }
        numberWithLargestChain[i] = maxCycleLengthIndex;
    }
    int t;
    cin >> t;

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << numberWithLargestChain[n] << endl;
    }
    return 0;
}
