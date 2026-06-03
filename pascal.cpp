#include <bits/stdc++.h>
using namespace std;

int comb(int n, int r)
{
    if (r == 0)
        return 1;
    if (r == 1)
        return n;
    return comb(n - 1, r - 1) * n / r;
}

vector<int> pascal(int n)
{
    vector<int> row;
    for (int i = 0; i <= n; i++)
    {
        row.push_back(comb(n, i));
    }
    return row;
}

int main()
{
    vector<int> row = pascal(4);
    for (int x : row)
    {
        cout << x << " ";
    }
    cout << endl;
}