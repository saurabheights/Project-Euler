#include <bits/stdc++.h>
using namespace std;

int numbers[101][101];

int computeMaxSumPath(int rows) {
    int sum[101][101];
    sum[0][0] = numbers[0][0];
    for (int i = 1; i < rows; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if(j == 0)
                sum[i][j] = numbers[i][j] + sum[i-1][j];
            else if( j < i)
                sum[i][j] = numbers[i][j] + max(sum[i-1][j], sum[i-1][j-1]);
            else
                sum[i][j] = numbers[i][j] + sum[i-1][j-1];
        }
    }

    int max1 = 0;
    for (int i = 0; i < rows; ++i)
    {
        max1 = max(sum[rows-1][i], max1);
    }
    return max1;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        int rows;
        cin >> rows;
        for(int i=0; i < rows; i++) {
            for (int j = 0; j <= i; ++j)
            {
                scanf("%d", &numbers[i][j]);
            }
        }
        cout << computeMaxSumPath(rows) << endl;
    }
    return 0;
}
