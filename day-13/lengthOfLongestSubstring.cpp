#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brute(string s)
    {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            vector<bool> charIdx(256, 0);
            for (int j = i; j < n; j++)
            {
                if (charIdx[s[j]] != 0)
                {
                    maxLen = max(maxLen, j - i);
                    break;
                }
                charIdx[s[j]] = true;
            }
        }
        return maxLen;
    }

    int optimalWithSlidingWindowAndHashmap(string s)
    {
        int maxLen = 0;
        vector<int> charIdx(256, -1);
        int l = 0, r = 0;
        while (r < s.size())
        {
            if (charIdx[s[r]] != -1)
            {
                l = max(l, charIdx[s[r]] + 1);
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            charIdx[s[r]] = r;
            r++;
        }
        return maxLen;
    }
    int lengthOfLongestSubstring(string s)
    {
        return optimalWithSlidingWindowAndHashmap(s);
    }
};

int main()
{
    Solution sol;
    string s;
    cin >> s;
    cout << sol.lengthOfLongestSubstring(s) << endl;
}