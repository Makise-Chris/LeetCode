#include <bits/stdc++.h>

using namespace std;

long getBiggestPalindromic(int length)
{
    long x = 1;
    for (int i = 0; i < length; ++i)
        x *= 10;
    x -= 1;
    return x;
}

long getSmallestPalindromic(int length)
{
    long x = 1;
    for (int i = 0; i < length - 1; ++i)
        x *= 10;
    x += 1;
    return x;
}

string nearestPalindromic(string n)
{
    int length = n.length();
    if (length < 2)
    {
        return to_string(stoi(n) - 1);
    }

    string same = n;
    string smaller = n;
    string bigger = n;

    if (length % 2 == 0)
    {
        string firstPart = n.substr(0, length / 2);
        long firstPartNumber = stol(firstPart);
        string firstPartSmaller = to_string(firstPartNumber - 1);
        string firstPartBigger = to_string(firstPartNumber + 1);
        for (int i = 0; i < firstPartSmaller.length(); i++)
        {
            smaller[i] = firstPartSmaller[i];
        }
        for (int i = 0; i < firstPartBigger.length(); i++)
        {
            bigger[i] = firstPartBigger[i];
        }
    }
    else
    {
        string firstPart = n.substr(0, length / 2 + 1);
        long firstPartNumber = stol(firstPart);
        string firstPartSmaller = to_string(firstPartNumber - 1);
        string firstPartBigger = to_string(firstPartNumber + 1);
        for (int i = 0; i < firstPartSmaller.length(); i++)
        {
            smaller[i] = firstPartSmaller[i];
        }
        for (int i = 0; i < firstPartBigger.length(); i++)
        {
            bigger[i] = firstPartBigger[i];
        }
    }

    for (int i = length / 2; i < length; i++)
    {
        same[i] = same[length - 1 - i];
        smaller[i] = smaller[length - 1 - i];
        bigger[i] = bigger[length - 1 - i];
    }

    long number = stol(n);
    long sameNumber = stol(same);
    long smallerNumber = stol(smaller);
    long biggerNumber = stol(bigger);
    long smallestPalindromic = getBiggestPalindromic(length - 1);
    long biggestPalindromic = getSmallestPalindromic(length + 1);
    cout << "same: " << same << ", smaller: " << smaller << ", bigger: " << bigger << endl;
    cout << "sameNumber: " << sameNumber << ", smallerNumber: " << smallerNumber << ", biggerNumber: " << biggerNumber << endl;
    cout << "smallestPalindromic: " << smallestPalindromic << ", biggestPalindromic: " << biggestPalindromic << endl;

    long minDiff = 1e18;
    long result = number;

    if (abs(number - biggestPalindromic) <= minDiff)
    {
        minDiff = abs(number - biggestPalindromic);
        result = biggestPalindromic;
    }

    if (abs(number - biggerNumber) <= minDiff && number != biggerNumber)
    {
        minDiff = abs(number - biggerNumber);
        result = biggerNumber;
    }

    if (abs(number - sameNumber) <= minDiff && number != sameNumber)
    {
        minDiff = abs(number - sameNumber);
        result = sameNumber;
    }

    if (abs(number - smallerNumber) <= minDiff && number != smallerNumber)
    {
        minDiff = abs(number - smallerNumber);
        result = smallerNumber;
    }

    if (abs(number - smallestPalindromic) <= minDiff)
    {
        minDiff = abs(number - smallestPalindromic);
        result = smallestPalindromic;
    }
    return to_string(result);
}

int main()
{
    string s = "10000000000000000";
    string result = nearestPalindromic(s);
    cout << "Nearest palindromic: " << result << endl;
}