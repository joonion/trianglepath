/*
    Approach 7: Dynamic Programming Final Solutions
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 256

int n, T[MAX][MAX], D[MAX][MAX], P[MAX][MAX], C[MAX][MAX];

void solve7()
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

void count7()
{
    for (int j = 0; j <= n; j++)
        C[n - 1][j] = 1;
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            switch (P[i][j]) {
                case 0: C[i][j] = C[i + 1][j];
                        break;
                case 1: C[i][j] = C[i + 1][j + 1];
                        break;
                case 2: C[i][j] = C[i + 1][j] +
                                  C[i + 1][j + 1];
                        break;
            }
}

void print_paths(int row, int col, vector<int>& path) 
{
    if (row == n - 1) {
        for (int n: path) 
            cout << n << " ";
        cout << T[row][col] << endl;
    }
    else {
        path.push_back(T[row][col]);
        switch (P[row][col]) {
            case 0: print_paths(row + 1, col, path); 
                    break;
            case 1: print_paths(row + 1, col + 1, path);
                    break;
            case 2: print_paths(row + 1, col, path);
                    print_paths(row + 1, col + 1, path);
                    break;
        }
        path.pop_back();
    }
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> T[i][j];

    solve7();
    count7();

    cout << D[0][0] << " " << C[0][0] << endl;
    vector<int> path;
    print_paths(0, 0, path);
}
