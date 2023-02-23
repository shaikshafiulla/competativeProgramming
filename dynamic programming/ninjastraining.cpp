#include <bits/stdc++.h>
using namespace std;
void print(auto &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int rec(int day, int last, vector<vector<int>> &task)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, task[0][i]);
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int gain = rec(day - 1, i, task) + task[day][i];
            maxi = max(maxi, gain);
        }
    }
    return maxi;
}
int main()
{
    int days;
    cin >> days;
    vector<vector<int>> task(days, vector<int>(3, 0));
    for (int i = 0; i < days; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            task[i][j] = x;
        }
    }
    cout << rec(days - 1, 3, task);
    // print(task);
}