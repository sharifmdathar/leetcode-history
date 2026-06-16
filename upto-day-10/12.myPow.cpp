
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        if (n == 0)
            return 1.0;
        if (n % 2 == 0)
        {
            double half = myPow(x, n / 2);
            return half * half;
        }
        else
        {
            double half = myPow(x, n / 2);
            return half * half * (n > 0 ? x : 1.0 / x);
        }
    }
};

int main()
{
    Solution sol;
    double x = 0;
    int n = -3;
    cout << sol.myPow(x, n) << endl;
    return 0;
}