#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s)
{
    int size = s.length();

    if (size < 2)
    {
        return s;
    }

    if (size == 2)
    {
        if (s[0] == s[1])
        {
            return s;
        }
        return s.substr(0, 1);
    }

    int dp[1000][1000];
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (j == i + 1 && s[i] == s[j])
            {
                dp[i][j] = 1;
            }
            else if (j == i + 2 && s[i] == s[j])
            {
                dp[i][j] = 1;
            }
            else if (s[i] != s[j])
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = -1;
            }
        }
    }

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - j; i++)
        {
            if (dp[i][i + j] > -1)
            {
                continue;
            }
            dp[i][i + j] = dp[i + 1][i + j - 1];
        }
    }

    int maxLength = 0;
    string result;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (dp[i][j] == 1 && j - i + 1 > maxLength)
            {
                maxLength = j - i + 1;
                result = s.substr(i, maxLength);
            }
        }
    }
    return result;
}

int main()
{
    string s = "xaabacxcabaaxcabaax";
    string result = longestPalindrome(s);
    cout << "Longest palindrome: " << result << endl;
}