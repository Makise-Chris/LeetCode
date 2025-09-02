// Solution by Nam Nguyen
#include <bits/stdc++.h>

using namespace std;

int lastRepeatedIndex(string s, char c)
{
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

int lengthOfLongestSubstring(string s)
{
    int length = s.length();
    if (length == 0)
    {
        return 0;
    }
    if (length == 1)
    {
        return 1;
    }
    int dp[100000];

    dp[0] = 1;
    if (s[1] == s[0])
    {
        dp[1] = 1;
    }
    else
    {
        dp[1] = 2;
    }

    for (int i = 2; i < length; i++)
    {
        string curCandidate = s.substr((i - 1) - dp[i - 1] + 1, dp[i - 1]);
        int lastIndex = lastRepeatedIndex(curCandidate, s[i]);
        dp[i] = dp[i - 1] - lastIndex;
    }

    int result = 0;
    for (int i = 0; i < length; i++)
    {
        cout << "dp[" << i << "] = " << dp[i] << endl;
        if (dp[i] > result)
            result = dp[i];
    }
    return result;
}

int main()
{
    string s = "dvdf";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}