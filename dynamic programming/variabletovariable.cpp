#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, int n, int m, vector<vector<int>> &grid)
{
    if (i == 0)
        return grid[0][j];
    if (j < 0 || j >= m)
        return -1e8;
    int u = f(i - 1, j, n, m, grid) + grid[i][j];
    int ld = f(i - 1, j - 1, n, m, grid) + grid[i][j];
    int rd = f(i - 1, j + 1, n, m, grid) + grid[i][j];
    return max(u, max(rd, ld));
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }
    int maxi = -1e8;
    for (int i = 0; i < m; i++)
    {
        int l = f(n - 1, i, n, m, grid);
        maxi = max(maxi, l);
    }
    cout << maxi << endl;
}