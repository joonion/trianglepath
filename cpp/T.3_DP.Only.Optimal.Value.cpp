/*
    Approach 3: Dynamic Programming for Only Optimal Value
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 256

int n, T[MAX][MAX], D[MAX][MAX];

void solve3()
{
    for (int j = 0; j <= n; j++)
        D[n - 1][j] = T[n - 1][j];
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            D[i][j] = T[i][j] + max(D[i + 1][j], D[i + 1][j + 1]);
}

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> T[i][j];

    solve3();
    cout << D[0][0] << endl;
}
