/*
    Approach 4: Dynamic Programming with Optimal Solution
*/
#include <iostream>
#include <vector>   
using namespace std;

#define MAX 256

int n, T[MAX][MAX], D[MAX][MAX], P[MAX][MAX];

void solve4()
{
    for (int j = 0; j <= n; j++)
        D[n - 1][j] = T[n - 1][j];
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++) {
            D[i][j] = T[i][j] + max(D[i + 1][j], D[i + 1][j + 1]);
            P[i][j] = (D[i + 1][j] > D[i + 1][j + 1]) ? 0 : 1;
        }
}

void print_paths()
{
    int col = 0;
    for (int row = 0; row < n - 1; row++) {
        cout << T[row][col] << " ";
        col += P[row][col];
    }
    cout << T[n - 1][col] << endl;
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> T[i][j];

    solve4();
    
    cout << D[0][0] << endl;
    print_paths();
}
