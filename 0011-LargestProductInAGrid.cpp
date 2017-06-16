#include <bits/stdc++.h>
using namespace std;

int main(){
    int ai =
    int a[20][20];
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            cin >> a[i][j];
        }
    }
    int maxProduct = -1;
    for (int row = 0; row < 20; ++row)
    {
        for (int col = 0; col < 20-3; ++col)
        {
            int p = a[row][col]*a[row][col+1]*a[row][col+2]*a[row][col+3];
            if(p > maxProduct)
                maxProduct = p;
        }
    }
    for (int col = 0; col < 20; ++col)
    {
        for (int row = 0; row < 20-3; ++row)
        {
            int p = a[row][col]*a[row+1][col]*a[row+2][col]*a[row+3][col];
            if(p > maxProduct)
                maxProduct = p;
        }
    }
    for (int row = 0; row < 20-3; ++row)
    {
        for (int col = 0; col < 20-3; ++col)
        {
            int p = a[row][col]*a[row+1][col+1]*a[row+2][col+2]*a[row+3][col+3];
            if(p > maxProduct)
                maxProduct = p;
        }
    }
    for (int row = 0; row < 20-3; ++row)
    {
        for (int col = 3; col < 20; ++col)
        {
            int p = a[row][col]*a[row+1][col-1]*a[row+2][col-2]*a[row+3][col-3];
            if(p > maxProduct)
                maxProduct = p;
        }
    }
    cout << maxProduct << endl;
    return 0;
}
