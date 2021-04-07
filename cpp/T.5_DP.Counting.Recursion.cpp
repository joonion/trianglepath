/*
    Approach 5: Dynamic Programming counting Optimal Solutions by Recursion
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 256

int n, T[MAX][MAX], D[MAX][MAX], P[MAX][MAX];

void solve5()
{
    for (int j = 0; j <= n; j++)
        D[n - 1][j] = T[n - 1][j];
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++) {
            D[i][j] = T[i][j] + max(D[i + 1][j], D[i + 1][j + 1]);
            P[i][j] = (D[i + 1][j] > D[i + 1][j + 1]) ? 0 : 
                      (D[i + 1][j] < D[i + 1][j + 1]) ? 1 : 2;
        }
}

int count5(int row, int col)
{
    if (row == n - 1)
        return 1;
    switch (P[row][col]) {
        case 0: return count5(row + 1, col);
        case 1: return count5(row + 1, col + 1);
        case 2: return count5(row + 1, col) +
                       count5(row + 1, col + 1);
    }
    return -1;
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> T[i][j];

    solve5();
    
    cout << D[0][0] << " ";
    cout << count5(0, 0) << endl;
}
