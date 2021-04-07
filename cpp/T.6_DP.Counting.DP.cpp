/*
    Approach 6: Dynamic Programming counting Optimal Solutions by D.P.
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 256

int n, T[MAX][MAX], D[MAX][MAX], P[MAX][MAX], C[MAX][MAX];

void solve6()
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

void count6()
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

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> T[i][j];

    solve6();
    count6();
    
    cout << D[0][0] << " " << C[0][0] << endl;
}
