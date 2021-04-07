/*
    Approach 1: Divide-and-Conquer using the Recursion
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 256

int n, T[MAX][MAX];

int solve1(int row, int col)
{
    if (row == n - 1)
        return T[row][col];
    else
        return T[row][col] + 
               max(solve1(row + 1, col), solve1(row + 1, col + 1));
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> T[i][j];
            
    cout << solve1(0, 0) << endl;
}
