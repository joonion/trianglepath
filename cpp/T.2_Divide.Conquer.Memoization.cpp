/*
    Approach 2: Divide-and-Conquer using the Memoization
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 256

int n, T[MAX][MAX], D[MAX][MAX];

int solve2(int row, int col)
{
    if (row == n - 1)
        D[row][col] = T[row][col];
    else if (D[row][col] == -1)
        D[row][col] = T[row][col] + 
                      max(solve2(row + 1, col), solve2(row + 1, col + 1));
    return D[row][col];
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            cin >> T[i][j];
            D[i][j] = -1;
        }
    cout << solve2(0, 0) << endl;
}
